#pragma once

#include <stdint.h>
#include "i_pixels_effect.h"

typedef uint8_t effect_t;

template <class Locator>
struct EffectInstance {
	IPixelsEffect<Locator>* effect;
	effect_t code;
};

template <class Locator, uint16_t Size = 16>
class EffectVector {
public:
	EffectVector& insert(effect_t code, IPixelsEffect<Locator>* effect) {
		if (size_ >= Size) {
			return *this;
		}
		effects_[size_].effect = effect;
		effects_[size_].code = code;
		names_[size_] = effect->getName();
		size_++;

		return *this;
	}

	IPixelsEffect<Locator>* getInstanceByCode(effect_t code) {
		for (size_t i = 0; i < size_; i++) {
			if (effects_[i].code == code) {
				return effects_[i].effect;
			}
		}
		return nullptr;
	}

	effect_t getCodeByInstance(IPixelsEffect<Locator>* effect) {
		for (size_t i = 0; i < size_; i++) {
			if (effects_[i].effect == effect) {
				return effects_[i].code;
			}
		}
		return 0;
	}

	IPixelsEffect<Locator>* getInstanceByName(const char* name) {
		for (size_t i = 0; i < size_; i++) {
			if (strcmp(effects_[i].effect->getName(), name) == 0) {
				return effects_[i].effect;
			}
		}
		return 0;
	}

	size_t capacity() const {
		return Size;
	}

	size_t size() {
		return size_;
	}

	const char** names() {
		return names_;
	}

private:
	EffectInstance<Locator> effects_[Size];
	const char* names_[Size];
	size_t size_ = 0;
};
