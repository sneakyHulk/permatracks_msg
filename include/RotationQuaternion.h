#pragma once

#include <ostream>

struct RotationQuaternion {
	float x;
	float y;
	float z;
	float w;
};

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion);