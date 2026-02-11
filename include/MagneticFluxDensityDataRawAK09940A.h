#pragma once

#include <ostream>

#pragma pack(push, 1)
struct MagneticFluxDensityDataRawAK09940A {
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

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawAK09940A const& d);