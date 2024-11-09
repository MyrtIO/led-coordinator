#pragma once

class IRenderer {
public:
	// Handle frame and update LED state.
	// Should return true if the state needs to be updated, false otherwise.
	virtual bool renderFrame();
};
