#include <Array.h>
#include <Box.h>
#include <Direction.h>
#include <DirectionVector.h>
#include <Magnet.h>
#include <MagneticFluxDensityData.h>
#include <MagneticFluxDensityDataRawAK09940A.h>
#include <MagneticFluxDensityDataRawLIS3MDL.h>
#include <MagneticFluxDensityDataRawMMC5983MA.h>
#include <MagneticFluxDensityIntegerData.h>
#include <Message.h>
#include <Pack.h>
#include <Position.h>

#include <cstdlib>
#include <iostream>
#include <sstream>

int main() {
	std::cout <<Message<Box<double, double>>{{{1, 2}}, 1000000000000000000, "main",} << std::endl;

	if ((std::ostringstream{} << Array<double, 3>{1.0, 2.0, 3.0}).str() != "[1, 2, 3]") return EXIT_FAILURE;
	if ((std::ostringstream{} << Magnet{1.2, 0.05, 1.4}).str() != "{'H': 1.2, 'R': 0.05, 'Br': 1.4}") return EXIT_FAILURE;
	if ((std::ostringstream{} << Direction{1.0, 2.0}).str() != "{'theta': 1, 'phi': 2}") return EXIT_FAILURE;
	if ((std::ostringstream{} << DirectionVector{1.0, 2.0, 3.0}).str() != "{'dx': 1, 'dy': 2, 'dz': 3}") return EXIT_FAILURE;
	if ((std::ostringstream{} << Box<double, double, double>{{1, 2, 3}}).str() != "(1, 2, 3)") return EXIT_FAILURE;
	if ((std::ostringstream{} << MagneticFluxDensityData{1.0, 2.0, 3.0}).str() != "{'x': 1, 'y': 2, 'z': 3}") return EXIT_FAILURE;
	if ((std::ostringstream{} << MagneticFluxDensityIntegerData{1, 2, 3}).str() != "{'x': 1, 'y': 2, 'z': 3}") return EXIT_FAILURE;
	if ((std::ostringstream{} << MagneticFluxDensityDataRawAK09940A{1, 2, 3}).str() != "{'x': 1, 'y': 2, 'z': 3}") return EXIT_FAILURE;
	if ((std::ostringstream{} << MagneticFluxDensityDataRawLIS3MDL{4, 5, 6}).str() != "{'x': 4, 'y': 5, 'z': 6}") return EXIT_FAILURE;
	if ((std::ostringstream{} << MagneticFluxDensityDataRawMMC5983MA{7, 8, 9}).str() != "{'x': 7, 'y': 8, 'z': 9}") return EXIT_FAILURE;
	if ((std::ostringstream{} << Position{7., 8., 9.}).str() != "{'x': 7, 'y': 8, 'z': 9}") return EXIT_FAILURE;
	if ((std::ostringstream{} << Pack{Position{7., 8., 9.}, Value<double>{1.0}}).str() != "{{'x': 7, 'y': 8, 'z': 9}, 1}") return EXIT_FAILURE;
	if ((std::ostringstream{} << Message<Box<double, double>>{{{1, 2}}, 2, "main",}).str() != "{'timestamp': 2, 'src': main, 'data': (1, 2)}")
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}