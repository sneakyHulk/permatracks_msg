#pragma once

#include <ostream>

struct Direction {
	double theta;
	double phi;
};

std::ostream& operator<<(std::ostream& os, Direction const& direction);