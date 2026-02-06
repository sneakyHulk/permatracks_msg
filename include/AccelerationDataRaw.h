#pragma once

#include <cstdint>
#include <ostream>

struct AccelerationDataRaw {
	std::int16_t x;
	std::int16_t y;
	std::int16_t z;
};

std::ostream& operator<<(std::ostream& os, AccelerationDataRaw const& acceleration);