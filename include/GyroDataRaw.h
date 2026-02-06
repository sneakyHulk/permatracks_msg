#pragma once

#include <cstdint>
#include <ostream>

struct GyroDataRaw {
	std::int16_t x;
	std::int16_t y;
	std::int16_t z;
};

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data);