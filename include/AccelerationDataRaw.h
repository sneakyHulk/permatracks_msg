#pragma once

#include <cstdint>
#include <ostream>

#pragma pack(push, 1)
struct AccelerationDataRaw {
	union {
		struct {
			std::int16_t ax;
			std::int16_t ay;
			std::int16_t az;
		};
		struct {
			std::uint8_t bytes[6];
		};
		struct {
			std::int16_t arr[3];
		};
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, AccelerationDataRaw const& acceleration);