#include "DirectionVector.h"

std::ostream &operator<<(std::ostream &os, DirectionVector const &direction) {
	os << "{'dx': " << direction.mx << ", 'dy': " << direction.my << ", 'dz': " << direction.mz << "}";
	return os;
}