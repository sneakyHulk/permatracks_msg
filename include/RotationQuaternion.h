#pragma once

#include <array>
#include <ostream>

#pragma pack(push, 1)
struct RotationQuaternion {
	union {
		struct {
			float rx;
			float ry;
			float rz;
			float rw;
		};
		std::array<std::uint8_t, 16> bytes;
		std::array<float, 4> arr;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, RotationQuaternion const& quaternion);