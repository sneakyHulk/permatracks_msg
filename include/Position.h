#pragma once

#include <ostream>

struct Position {
	double x;
	double y;
	double z;
};

std::ostream& operator<<(std::ostream& os, Position const& position);