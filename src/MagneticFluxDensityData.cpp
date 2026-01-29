#include "MagneticFluxDensityData.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityData const& d) {
	os << "{'x': " << d.x << ", 'y': " << d.y << ", 'z': " << d.z << "}";

	return os;
}