#pragma once

#include <array>
#include <ostream>

#pragma pack(push, 1)
struct GravityVector {
	union {
		struct {
			float gvx;
			float gvy;
			float gvz;
		};
		std::array<std::uint8_t, 12> bytes;
		std::array<float, 3> arr;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GravityVector const& gravity_vector);