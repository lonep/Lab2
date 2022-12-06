#pragma once
#include "SDL.h"
#include "Texture.h"

class ColorData
{
public:
	enum Colors {
		red = 0,
		green,
		blue
	};

	void setInsideMode(Colors color);
	void setOutsideMode(Colors color);

	SDL_Color getInsideZoneColor(Uint8 parameter) const;
	SDL_Color getOutsideZoneColor(Uint8 parameter) const;

	Texture* texture;

private:
	int insideMode = 0;
	int outsideMode = 0;

	

	SDL_Color insideZoneColor = SDL_Color(255, 0, 0, 255);
	SDL_Color outsideZoneColor = SDL_Color(0, 255, 0, 255);
};

