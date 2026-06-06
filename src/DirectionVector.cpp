#include "DirectionVector.h"

bool DirectionVector::operator==(DirectionVector const &other) const { return mx == other.mx && my == other.my && mz == other.mz; }
std::ostream &operator<<(std::ostream &os, DirectionVector const &direction) {
	os << "{'dx': " << direction.mx << ", 'dy': " << direction.my << ", 'dz': " << direction.mz << "}";
	return os;
}