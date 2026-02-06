#pragma once

#include <cstdint>
#include <ostream>

#pragma pack(push, 1)
struct GyroDataRaw {
	union {
		struct {
			std::int16_t gx;
			std::int16_t gy;
			std::int16_t gz;
		};
		struct {
			std::uint8_t bytes[6];
		};
		struct {
			std::int16_t arr[3];
		};
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data);