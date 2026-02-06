#include "AccelerationData.h"

std::ostream& operator<<(std::ostream& os, AccelerationData const& acceleration) {
	os << "{'x': " << acceleration.ax << ", 'y': " << acceleration.ay << ", 'z': " << acceleration.az << "}";
	return os;
}