#pragma once
#include <ostream>

struct GyroData {
	float x;
	float y;
	float z;
};

std::ostream& operator<<(std::ostream& os, GyroData const& gyro_data);