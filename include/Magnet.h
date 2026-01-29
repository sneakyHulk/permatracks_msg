#pragma once

#include <ostream>

struct Magnet {
	double H;   // m
	double R;   // m
	double Br;  // T
};

std::ostream& operator<<(std::ostream& os, Magnet const& m);