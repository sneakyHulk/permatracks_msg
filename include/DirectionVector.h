#pragma once

#include <ostream>

struct DirectionVector {
	double mx;
	double my;
	double mz;
};

std::ostream& operator<<(std::ostream& os, DirectionVector const& direction);