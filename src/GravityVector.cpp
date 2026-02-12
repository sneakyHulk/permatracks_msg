#include "GravityVector.h"

std::ostream& operator<<(std::ostream& os, GravityVector const& gravity_vector) {
	os << "{'gvx': " << gravity_vector.gvx << ", 'gvy': " << gravity_vector.gvy << ", 'gvz': " << gravity_vector.gvz << "}";

	return os;
}