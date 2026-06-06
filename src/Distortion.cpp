#include "Distortion.h"

bool Distortion::operator==(Distortion const& other) const { return frequency == other.frequency && amplitude == other.amplitude && direction == other.direction; }
std::ostream& operator<<(std::ostream& os, Distortion const& p) { return os << "{ frequency: " << p.frequency << ", amplitude: " << p.amplitude << ", direction: " << p.direction << " }"; }
