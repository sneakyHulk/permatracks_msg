#include "Magnet.h"

std::ostream& operator<<(std::ostream& os, Magnet const& m) {
	os << "{'H': " << m.H << ", 'R': " << m.R << ", 'Br': " << m.Br << "}";

	return os;
}