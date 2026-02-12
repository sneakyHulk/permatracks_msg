#pragma once

#include <array>
#include <ostream>

#pragma pack(push, 1)
struct GyroBiasVector {
	union {
		struct {
			float gbx;
			float gby;
			float gbz;
		};
		std::array<std::uint8_t, 12> bytes;
		std::array<float, 3> arr;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GyroBiasVector const& gyro_bias_vector);