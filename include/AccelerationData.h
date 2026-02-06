#pragma once
#include <ostream>

#pragma pack(push, 1)
struct AccelerationData {
	float x;
	float y;
	float z;
};


std::ostream& operator<<(std::ostream& os, AccelerationData const& acceleration);