#pragma once

#include <ostream>

struct DirectionVector {
	double mx;
	double my;
	double mz;

	bool operator==(DirectionVector const& other) const;
};

std::ostream& operator<<(std::ostream& os, DirectionVector const& direction);