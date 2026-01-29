#pragma once

#include <cstdint>
#include <ostream>

struct MagneticFluxDensityIntegerData {
	std::int32_t x;
	std::int32_t y;
	std::int32_t z;
};

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityIntegerData const& d);