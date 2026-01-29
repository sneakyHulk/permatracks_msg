#include "MagneticFluxDensityDataRawMMC5983MA.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawMMC5983MA const& d) {
	os << "{'x': " << d.x << ", 'y': " << d.y << ", 'z': " << d.z << "}";

	return os;
}