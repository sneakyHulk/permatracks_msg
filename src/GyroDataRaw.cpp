#include "GyroDataRaw.h"

std::ostream& operator<<(std::ostream& os, GyroDataRaw const& gyro_data) {
	os << "{'gx': " << gyro_data.gx << ", 'gy': " << gyro_data.gy << ", 'gz': " << gyro_data.gz << "}";
	return os;
}