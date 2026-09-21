#include "MagneticFluxDensityDatapointRaw.h"

std::ostream& operator<<(std::ostream& os, MagneticFluxDensityDatapointRaw const& d) {
	os << "{'datapoint': " << d.datapoint << "}";

	return os;
}