#pragma once
#include <ostream>

struct AccelerationData {
	float x;
	float y;
	float z;
};


std::ostream& operator<<(std::ostream& os, AccelerationData const& acceleration);