#pragma once
#include <ostream>

#pragma pack(push, 1)
struct GyroData {
	float x;
	float y;
	float z;
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GyroData const& gyro_data);