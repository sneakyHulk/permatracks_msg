#include "GyroBiasVector.h"

std::ostream& operator<<(std::ostream& os, GyroBiasVector const& gyro_bias_vector) {
	os << "{'gbx': " << gyro_bias_vector.gbx << ", 'gby': " << gyro_bias_vector.gby << ", 'gbz': " << gyro_bias_vector.gbz << "}";

	return os;
}