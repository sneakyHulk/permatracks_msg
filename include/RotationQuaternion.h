#pragma once

#include <ostream>

#pragma pack(push, 1)
struct RotationQuaternion {
	float rx;
	float ry;
	float rz;
	float rw;
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion);