#include "RotationQuaternion.h"

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion) {
	os << "{'x': " << quaternion.rx << ", 'y': " << quaternion.ry << ", 'z': " << quaternion.rz << ", 'w': " << quaternion.rw << "}";
	return os;
}