#pragma once

#include <cstdint>
#include <ostream>

#pragma pack(push, 1)
struct GyroDataRaw {
	union {
		struct {
			std::int16_t x;
			std::int16_t y;
			std::int16_t z;
		};
		struct {
			std::uint8_t bytes[6];
		};
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data);