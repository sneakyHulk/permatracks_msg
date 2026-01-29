#include "MagneticFluxDensityDataRawLIS3MDL.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawLIS3MDL const& d) {
	os << "{'x': " << d.x << ", 'y': " << d.y << ", 'z': " << d.z << "}";

	return os;
}