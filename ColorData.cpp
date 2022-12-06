#include "ColorData.h"

void ColorData::setInsideMode(Colors color)
{
	insideMode = color;
}

void ColorData::setOutsideMode(Colors color)
{
	outsideMode = color;
}

SDL_Color ColorData::getInsideZoneColor(Uint8 parameter) const
{
	switch (insideMode)
	{
	case (Colors::red):
		return SDL_Color(parameter, 0, 0, 255);
		//texture->UpdateTexture();
		break;
	case (Colors::green):
		return SDL_Color(0, parameter, 0, 255);
		break;
	case (Colors::blue):
		return SDL_Color(0, 0, parameter, 255);
		break;
	}

	return insideZoneColor;
}

SDL_Color ColorData::getOutsideZoneColor(Uint8 parameter) const
{
	switch (outsideMode)
	{
	case (Colors::red):
		return SDL_Color(parameter, 0, 0, 255);
		break;
	case (Colors::green):
		return SDL_Color(0, parameter, 0, 255);
		break;
	case (Colors::blue):
		return SDL_Color(0, 0, parameter, 255);
		break;
	}

	return outsideZoneColor;
}