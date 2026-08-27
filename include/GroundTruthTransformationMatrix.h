#pragma once

#include <array>
#include <ostream>

#pragma pack(push, 1)
struct GroundTruthTransformationMatrix {
	union {
		struct {
			double tm0;
			double tm1;
			double tm2;
			double tm3;
			double tm4;
			double tm5;
			double tm6;
			double tm7;
			double tm8;
			double tm9;
			double tm10;
			double tm11;
			double tm12;
		};
		std::array<std::uint8_t, 12 * sizeof(double)> bytes;
		std::array<double, 12> arr;
	};
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& os, GroundTruthTransformationMatrix const& tm);