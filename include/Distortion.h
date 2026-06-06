#pragma once

#include "DirectionVector.h"

struct Distortion {
	double frequency;
	double amplitude;
	DirectionVector direction;

	bool operator==(Distortion const& other) const;
};
std::ostream& operator<<(std::ostream& os, Distortion const& p);