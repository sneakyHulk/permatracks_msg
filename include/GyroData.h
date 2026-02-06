#pragma once
#include <ostream>

struct GyroData {
	float gx;
	float gy;
	float gz;
};

std::ostream& operator<<(std::ostream& os, GyroData const& gyro_data);