#include "TemperatureDataRaw.h"

std::ostream& operator<<(std::ostream& os, TemperatureDataRaw const& d) {
	os << "{'datapoint': " << d.datapoint << "}";

	return os;
}
