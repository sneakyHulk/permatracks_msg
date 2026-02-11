#pragma once

#include <ostream>
#include <array>

#pragma pack(push, 1)
struct MagneticFluxDensityDataRawMMC5983MA {
	union {
		struct {
			std::int32_t x : 19;
			std::int32_t y : 19;
			std::int32_t z : 18;
		};
		std::array<std::uint8_t, 7> bytes;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawMMC5983MA const& d);