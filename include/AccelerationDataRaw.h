#pragma once

#include <cstdint>
#include <ostream>
#include <array>

#pragma pack(push, 1)
struct AccelerationDataRaw {
	union {
		struct {
			std::int16_t ax;
			std::int16_t ay;
			std::int16_t az;
		};
		std::array<std::uint8_t, 6> bytes;
		std::array<std::int16_t, 6> arr;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, AccelerationDataRaw const& acceleration);