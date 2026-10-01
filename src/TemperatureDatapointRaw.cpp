#include "TemperatureDatapointRaw.h"

std::ostream& operator<<(std::ostream& os, TemperatureDatapointRaw const& d) {
	os << "{'datapoint': " << d.datapoint << "}";

	return os;
}
