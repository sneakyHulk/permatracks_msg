#pragma once
#include <array>
#include <cstdint>
#include <ostream>

#pragma pack(push, 1)
struct MagneticFluxDensityDatapointRaw {
	union {
		struct {
			std::int32_t datapoint : 24;
		};
		std::array<std::uint8_t, 3> bytes;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDatapointRaw const& d);