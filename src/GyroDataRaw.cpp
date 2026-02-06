#include "GyroDataRaw.h"

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data) {
	os << "{'x': " << gyro_data.x << ", 'y': " << gyro_data.y << ", 'z': " << gyro_data.z << "}";
	return os;
}