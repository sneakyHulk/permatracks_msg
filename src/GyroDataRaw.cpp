#include "GyroDataRaw.h"

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data) {
	os << "{'x': " << gyro_data.gx << ", 'y': " << gyro_data.gy << ", 'z': " << gyro_data.gz << "}";
	return os;
}