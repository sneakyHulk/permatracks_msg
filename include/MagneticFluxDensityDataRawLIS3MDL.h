#pragma once

#include <ostream>
#include <array>

#pragma pack(push, 1)
struct MagneticFluxDensityDataRawLIS3MDL {
	union {
		struct {
			std::int16_t x;
			std::int16_t y;
			std::int16_t z;
		};
		std::array<std::uint8_t, 6> bytes;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawLIS3MDL const& d);