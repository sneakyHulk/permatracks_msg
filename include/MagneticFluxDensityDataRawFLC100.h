#pragma once
#include <array>
#include <cstdint>
#include <ostream>

#pragma pack(push, 1)
struct MagneticFluxDensityDataRawFLC100 {
	union {
		struct {
			std::int32_t data : 24;
		};
		std::array<std::uint8_t, 3> bytes;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawFLC100 const& d);