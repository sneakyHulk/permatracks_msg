#include "GyroData.h"

std::ostream& operator<<(std::ostream& os, GyroData const& gyro_data) {
	os << "{'x': " << gyro_data.gx << ", 'y': " << gyro_data.gy << ", 'z': " << gyro_data.gz << "}";
	return os;
}