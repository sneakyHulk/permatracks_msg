#include "RotationQuaternion.h"

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion) {
	os << "{'x': " << quaternion.x << ", 'y': " << quaternion.y << ", 'z': " << quaternion.z << ", 'w': " << quaternion.w << "}";
	return os;
}