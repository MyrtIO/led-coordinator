#include "white_color.h"
#include <math.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define limit8(a) min(max(a, 0.0), 255.0)

void kelvin2rgb(kelvin_t temperature, RGBColor& color) {
	temperature /= 100;
	double accumulator;

	if (temperature <= 66) {
		color.r = 255;
	} else {
		accumulator = temperature - 60;
		accumulator = 329.698727466 * pow(accumulator, -0.1332047592);
		color.r = limit8(accumulator);
	}

	if (temperature <= 66.0) {
		accumulator = temperature;
		accumulator = 99.4708025861 * log(accumulator) - 161.1195681661;
		color.g = limit8(accumulator);
	} else {
		accumulator = temperature - 60.0;
		accumulator = 288.1221695283 * pow(accumulator, -0.0755148492);
		color.g = limit8(accumulator);
	}

	if (temperature >= 66.0) {
		color.b = 255;
	} else {
		if (temperature <= 19.0) {
			color.b = 0;
		} else {
			accumulator = temperature - 10.0;
			accumulator = 138.5177312231 * log(accumulator) - 305.0447927307;
			color.b = limit8(accumulator);
		}
	}
}
