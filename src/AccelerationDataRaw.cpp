#include "AccelerationDataRaw.h"

std::ostream& operator<<(std::ostream& os, AccelerationDataRaw const& acceleration) {
	os << "{'x': " << acceleration.x << ", 'y': " << acceleration.y << ", 'z': " << acceleration.z << "}";
	return os;
}