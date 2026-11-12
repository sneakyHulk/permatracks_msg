#pragma once

#include <cstddef>
#include <ostream>

struct MagneticFluxDensityData {
	double x;
	double y;
	double z;

	// component k: 0 = x, 1 = y, 2 = z (read and write)
	double& operator[](std::size_t const k) { return k == 0 ? x : k == 1 ? y : z; }
	double const& operator[](std::size_t const k) const { return k == 0 ? x : k == 1 ? y : z; }
};

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityData const& d);