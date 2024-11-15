#pragma once

#include <stdint.h>
#include "i_pixels_effect.h"

typedef uint8_t effect_t;

template <class Locator, uint16_t Size = 16>
class EffectList {
public:
	EffectList& insert(IPixelsEffect<Locator>* effect) {
		if (size_ >= Size) {
			return *this;
		}
		effects_[size_] = effect;
		names_[size_] = effect->getName();
		size_++;

		return *this;
	}

	IPixelsEffect<Locator>* find(const char* name) {
		for (size_t i = 0; i < size_; i++) {
			if (strcmp(effects_[i]->getName(), name) == 0) {
				return effects_[i];
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
	IPixelsEffect<Locator>* effects_[Size];
	const char* names_[Size];
	size_t size_ = 0;
};
