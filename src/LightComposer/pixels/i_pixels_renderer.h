#pragma once

#include <LightComposer/i_renderer.h>

template <class Locator>
class IPixelsRenderer: public IRenderer, public IEffectChanger {
public:
	virtual void attachComposer(IEffectProvider* composer, ILightHAL* hal) = 0;

	virtual void setColor(const RGBColor color) = 0;
	virtual void setEffect(IPixelsEffect<Locator>* effect, bool force = false) = 0;
	virtual void setLocator(Locator* locator) = 0;
	virtual RGBColor getColor();
	virtual IPixelsEffect<Locator>* getEffect();
};
