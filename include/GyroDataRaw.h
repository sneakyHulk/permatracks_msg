#pragma once

#include <cstdint>
#include <ostream>
#include <array>

#pragma pack(push, 1)
struct GyroDataRaw {
	union {
		struct {
			std::int16_t gx;
			std::int16_t gy;
			std::int16_t gz;
		};
		std::array<std::uint8_t, 6> bytes;
		std::array<std::int16_t, 6> arr;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data);