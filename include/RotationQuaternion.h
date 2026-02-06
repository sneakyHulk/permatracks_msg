#pragma once

#include <ostream>

#pragma pack(push, 1)
struct RotationQuaternion {
	float x;
	float y;
	float z;
	float w;
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion);