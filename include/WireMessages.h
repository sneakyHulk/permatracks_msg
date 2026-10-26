#pragma once

#include <GravityVector.h>
#include <GyroBiasVector.h>
#include <MagneticFluxDensityDataRawAK09940A.h>
#include <MagneticFluxDensityDataRawLIS3MDL.h>
#include <MagneticFluxDensityDataRawMMC5983MA.h>
#include <RotationQuaternion.h>

#include <array>
#include <cstddef>
#include <cstdint>

#include "TemperatureDataRaw.h"

// Messages sent between device and host, framed by Parser2:
//   fixed size:    [tag][header][fields][crc16][tag], the packed struct is the payload
//   variable size: [tag][header][payload: n][n][crc16][tag]
// Every message derives from Header and has a static constexpr char tag.
// Header::timestamp is always the time the sender sends the message, measurements carry their own measurement_timestamp.

#pragma pack(push, 1)
struct Header {
	std::uint64_t timestamp;  // sender's time when the message is sent
};

// device -> host, timestamp = t0: device time when the request is sent
struct TimeSyncRequestWireMessage : Header {
	static constexpr char tag = 'R';
};

// host -> device, timestamp = t2: host time when the response is sent
struct TimeSyncResponseWireMessage : Header {
	static constexpr char tag = 'R';
	std::uint64_t t1;  // host time when the request was received
};

// host -> device, USB SOF time sync: USB frame `frame` started at host time frame_ns, one frame lasts ps_per_frame in host time
struct SofSyncWireMessage : Header {
	static constexpr char tag = 'S';
	std::uint64_t frame_ns;  // host time at the start of the frame
	std::uint16_t frame;     // 11-bit USB frame number
	std::uint32_t ps_per_frame;
};

// device -> host: please send a SofSyncWireMessage (mag-array-v3; at the start, and again whenever the device wants a new one)
struct SofSyncRequestWireMessage : Header {
	static constexpr char tag = 'S';
};

// device -> host, two device clocks read right after each other (host time in ns), the host compares them with its arrival
// time and with each other. Which clocks they are is up to the device (mag-array-v3-time: two UsbSofClock::now() right after each other).
struct TimeCompareWireMessage : Header {
	static constexpr char tag = 'C';
	std::uint64_t time1_ns;
	std::uint64_t time2_ns;
};

// host -> device, ping: timestamp = t0, host (mach) time when the ping is sent
struct PingRequestWireMessage : Header {
	static constexpr char tag = 'P';
};

// device -> host, answered right away: one clock read when the ping was received, t0 sent back.
// The clock's time must lie between t0 and the host's receive time t3, whatever the transfer takes.
struct PingResponseWireMessage : Header {
	static constexpr char tag = 'P';
	std::uint64_t t0;       // timestamp of the PingRequestWireMessage
	std::uint64_t time_ns;  // the clock when the ping was received
};

template <std::size_t N, typename T> // can be MagneticFluxDensityDataRawAK09940A
struct MagneticFluxDensityRawWireMessage : Header {
	static constexpr char tag = 'M';
	std::uint64_t measurement_timestamp;  // when the values were measured
	std::int32_t scale;
	std::array<T, N> data;
};

// mag-array-v1: 16 LIS3MDL and 25 MMC5983MA in one message, each block with its own scale (LSB per T)
struct MagArrayV1MagneticFluxDensityRawWireMessage : Header {
	static constexpr char tag = 'M';
	std::uint64_t measurement_timestamp;  // when the values were measured
	std::int32_t scale_lis3mdl;
	std::array<MagneticFluxDensityDataRawLIS3MDL, 16> lis3mdl;
	std::int32_t scale_mmc5983ma;
	std::array<MagneticFluxDensityDataRawMMC5983MA, 25> mmc5983ma;
};

template <std::size_t N>
struct TemperatureDataRawWireMessage : Header {
	static constexpr char tag = 'T';
	std::uint64_t measurement_timestamp;  // when the values were measured
	float offset;
	float scale;
	std::array<TemperatureDataRaw, N> data;
};

struct AccelerationWireMessage : Header {
	static constexpr char tag = 'A';
	std::uint64_t measurement_timestamp;  // when the values were measured
	float scale;
	std::int16_t ax, ay, az;
};

struct GyroWireMessage : Header {
	static constexpr char tag = 'G';
	std::uint64_t measurement_timestamp;  // when the values were measured
	float scale;
	std::int16_t gx, gy, gz;
};

struct QuaternionWireMessage : Header {
	static constexpr char tag = 'Q';
	std::uint64_t measurement_timestamp;  // when the values were measured
	RotationQuaternion data;
};

struct GravityWireMessage : Header {
	static constexpr char tag = 'V';
	std::uint64_t measurement_timestamp;  // when the values were measured
	GravityVector data;
};

struct GyroBiasWireMessage : Header {
	static constexpr char tag = 'B';
	std::uint64_t measurement_timestamp;  // when the values were measured
	GyroBiasVector data;
};
#pragma pack(pop)

#ifndef ARDUINO  // host only, the payload lives on the heap
#include <string>

// variable size, payload up to max_payload_size bytes
struct InfoWireMessage : Header {
	static constexpr char tag = 'I';
	static constexpr std::size_t max_payload_size = 255;
	std::string payload;
};
#endif
