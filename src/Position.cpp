#include "Position.h"

std::ostream& operator<<(std::ostream& os, Position const& position) {
	os << "{'x': " << position.x << ", 'y': " << position.y << ", 'z': " << position.z << "}";

	return os;
}