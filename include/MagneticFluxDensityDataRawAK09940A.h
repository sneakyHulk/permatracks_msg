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
		struct {
			std::uint8_t bytes[7];
		};
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawAK09940A const& d);