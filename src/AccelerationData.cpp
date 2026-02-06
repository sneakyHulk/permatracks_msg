#include "AccelerationData.h"

std::ostream& operator<<(std::ostream& os, AccelerationData const& acceleration) {
	os << "{'x': " << acceleration.x << ", 'y': " << acceleration.y << ", 'z': " << acceleration.z << "}";
	return os;
}