#include "MagneticFluxDensityDataRawAK09940A.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawAK09940A const& d) {
	os << "{'x': " << d.x << ", 'y': " << d.y << ", 'z': " << d.z << "}";

	return os;
}