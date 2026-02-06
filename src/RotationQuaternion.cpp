#include "RotationQuaternion.h"

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion) {
	os << "{'rx': " << quaternion.rx << ", 'ry': " << quaternion.ry << ", 'rz': " << quaternion.rz << ", 'rw': " << quaternion.rw << "}";
	return os;
}