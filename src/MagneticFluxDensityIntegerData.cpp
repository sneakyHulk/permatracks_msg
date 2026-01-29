#include "MagneticFluxDensityIntegerData.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityIntegerData const& d) {
	os << "{'x': " << d.x << ", 'y': " << d.y << ", 'z': " << d.z << "}";

	return os;
}