#include "AccelerationDataRaw.h"

std::ostream& operator<<(std::ostream& os, AccelerationDataRaw const& acceleration) {
	os << "{'x': " << acceleration.ax << ", 'y': " << acceleration.ay << ", 'z': " << acceleration.az << "}";
	return os;
}