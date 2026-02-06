#include "AccelerationDataRaw.h"

std::ostream& operator<<(std::ostream& os, AccelerationDataRaw const& acceleration) {
	os << "{'ax': " << acceleration.ax << ", 'ay': " << acceleration.ay << ", 'az': " << acceleration.az << "}";
	return os;
}