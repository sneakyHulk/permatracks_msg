#include "MagneticFluxDensityDataRawFLC100.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDataRawFLC100 const& d) {
	os << "{'datapoint': " << d.data << "}";

	return os;
}