#pragma once
#include <array>
#include <cstdint>
#include <ostream>

#pragma pack(push, 1)
struct TemperatureDatapointRaw {
	union {
		struct {
			std::uint16_t datapoint;  // 12-bit ADC code (0..4095) in 16 bits
		};
		std::array<std::uint8_t, 2> bytes;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, TemperatureDatapointRaw const& d);
