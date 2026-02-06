#pragma once
#include <ostream>

struct AccelerationData {
	float ax;
	float ay;
	float az;
};


std::ostream& operator<<(std::ostream& os, AccelerationData const& acceleration);