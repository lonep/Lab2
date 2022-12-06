#pragma once
#include <functional>
#include "SDL.h"
class MImageCalculator
{
public:

	enum FunctionZone
	{
		Negative, Positive
	};

	struct MImagePixelData
	{
		double nx, ny, nz, nd;
		FunctionZone zone;
	};

	enum MImageType
	{
		Cx, Cy, Cz, Cd
	};

	MImageCalculator(const std::function<float(SDL_Point pixel)>& computeFunction);
	std::vector<std::vector<MImagePixelData>> GetSpaceData(SDL_Point spaceSize);
	MImagePixelData GetPixelData(SDL_Point point);

private:
	std::function<float(SDL_Point)> _computeFunction;
};

