#pragma once

#include "DirectionVector.h"

struct Distortion {
	double frequency;
	double amplitude;
	DirectionVector direction;
	double linearity = 1.0;  // of the oscillation: 1 along one direction (direction is meaningful), 1/sqrt(2) a circle

	bool operator==(Distortion const& other) const;
	bool operator<(Distortion const& other) const;
	bool operator>(Distortion const& other) const;
};
std::ostream& operator<<(std::ostream& os, Distortion const& p);