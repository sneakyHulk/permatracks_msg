#pragma once

#include <GravityVector.h>
#include <GyroBiasVector.h>
#include <MagneticFluxDensityDataRawAK09940A.h>
#include <RotationQuaternion.h>

#include <array>
#include <cstddef>
#include <cstdint>

#include "TemperatureDataRaw.h"

// Messages sent between device and host, framed by Parser2:
//   fixed size:    [tag][header][fields][crc16][tag], the packed struct is the payload
//   variable size: [tag][header][payload: n][n][crc16][tag]
// Every message derives from Header and has a static constexpr char tag.

#pragma pack(push, 1)
struct Header {
	std::uint64_t timestamp;
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

// host -> device, USB SOF time sync: timestamp = host time at the start of USB frame `frame`, one frame lasts ps_per_frame in host time
struct SofSyncWireMessage : Header {
	static constexpr char tag = 'S';
	std::uint16_t frame;  // 11-bit USB frame number
	std::uint32_t ps_per_frame;
};

// device -> host, both device clocks read right after each other (host time in ns), the header stays empty
struct TimeCompareWireMessage : Header {
	static constexpr char tag = 'C';
	std::uint64_t ntp_ns;  // NtpClock
	std::uint64_t sof_ns;  // UsbSofClock
};

template <std::size_t N, typename T> // can be MagneticFluxDensityDataRawAK09940A
struct MagneticFluxDensityRawWireMessage : Header {
	static constexpr char tag = 'M';
	std::int32_t scale;
	std::array<T, N> data;
};

template <std::size_t N>
struct TemperatureDataRawWireMessage : Header {
	static constexpr char tag = 'T';
	float offset;
	float scale;
	std::array<TemperatureDataRaw, N> data;
};

struct AccelerationWireMessage : Header {
	static constexpr char tag = 'A';
	float scale;
	std::int16_t ax, ay, az;
};

struct GyroWireMessage : Header {
	static constexpr char tag = 'G';
	float scale;
	std::int16_t gx, gy, gz;
};

struct QuaternionWireMessage : Header {
	static constexpr char tag = 'Q';
	RotationQuaternion data;
};

struct GravityWireMessage : Header {
	static constexpr char tag = 'V';
	GravityVector data;
};

struct GyroBiasWireMessage : Header {
	static constexpr char tag = 'B';
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
