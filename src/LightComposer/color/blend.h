#pragma once

#include "rgb_color.h"
#include <LightComposer/math/blend.h>

static inline RGBColor blendColors(
	const RGBColor &a,
	const RGBColor &b,
	fract_t frac
) {
	return RGBColor(
		blend8(a.r, b.r, frac),
		blend8(a.g, b.g, frac),
		blend8(a.b, b.b, frac)
	);
}
