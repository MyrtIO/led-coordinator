#pragma once

#include "rgb_color.h"

typedef unsigned short mireds_t;
typedef unsigned short kelvin_t;

static inline kelvin_t mireds2kelvin(mireds_t mireds) {
	return 1000000 / mireds;
}

static inline mireds_t kelvin2mireds(kelvin_t kelvin) {
	return 1000000 / kelvin;
}

void kelvin2rgb(kelvin_t temperature, RGBColor& color);

// Warm white, about 3000K
#define WARM_WHITE_MIREDS 333

struct WhiteColor {
	WhiteColor(
		mireds_t temperature = 285
	) : mireds_(temperature) {
		kelvin_ = mireds2kelvin(temperature);
		kelvin2rgb(kelvin_, rgb_);
	}

	const kelvin_t kelvin() const {
		return kelvin_;
	}

	const mireds_t mireds() const {
		return mireds_;
	}

	const RGBColor& rgb() const {
		return rgb_;
	}

	operator RGBColor() const {
		return rgb_;
	}

	void setKelvin(kelvin_t temperature) {
		kelvin_ = temperature;
		mireds_ = kelvin2mireds(kelvin_);
		kelvin2rgb(kelvin_, rgb_);
	}

	void setMireds(mireds_t temperature) {
		mireds_ = temperature;
		kelvin_ = mireds2kelvin(mireds_);
		kelvin2rgb(kelvin_, rgb_);
	}

private:
	mireds_t mireds_;
	kelvin_t kelvin_;
	RGBColor rgb_;
};
