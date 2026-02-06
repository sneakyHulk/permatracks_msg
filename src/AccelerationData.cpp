#include "AccelerationData.h"

std::ostream& operator<<(std::ostream& os, AccelerationData const& acceleration) {
	os << "{'ax': " << acceleration.ax << ", 'ay': " << acceleration.ay << ", 'az': " << acceleration.az << "}";
	return os;
}