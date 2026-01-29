#include "Direction.h"

std::ostream &operator<<(std::ostream &os, Direction const &direction) {
	os << "{'theta': " << direction.theta << ", 'phi': " << direction.phi << "}";

	return os;
}