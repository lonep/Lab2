#pragma once
#include "Functions.h"
#include "Texture.h"
using namespace Functions;

float calcByPoint(SDL_Point point, Texture& texture)
{
	float circle1 = Circle({ 200, 200 }, 100, point);
	float circle2 = Circle({ 500, 200 }, 100, point);
	float circle3 = Circle({ 350, 350 }, 150, point);
	float circle_eye1 = -Circle({ 250, 300 }, 50, point);
	float circle_eye2 = -Circle({ 400, 300 }, 50, point);
	float ellipse = -Ellipse({ 300, 450 }, point, {70, 25}) * 100;
	return RAnd(RAnd(RAnd(ROr(ROr(circle1,circle2), circle3), circle_eye1), circle_eye2), ellipse);
}

void lab2(Texture& texture)
{
	for (int y = 0; y < texture.GetSize().y; ++y)
	{
		for (int x = 0; x < texture.GetSize().x; ++x)
		{
			// Расчитываем площадку из трех значений
			int x1 = x, y1 = y;
			int x2 = x, y2 = y + 1;
			int x3 = x + 1, y3 = y;
			float z1 = calcByPoint({ x1, y1 }, texture);
			float z2 = calcByPoint({ x2, y2 }, texture);
			float z3 = calcByPoint({ x3, y3 }, texture);

			// Считаем дискременанты
			float Ai = y1 * (z2 - z3) - y2 * (z1 - z3) + y3 * (z1 - z2);
			float Bi = -(x1 * (z2 - z3) - x2 * (z1 - z3) + x3 * (z1 - z2));
			float Ci = x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2);
			float Di = x1 * (y2 * z3 - y3 * z2) - x2 * (y1 * z3 - y3 * z1) + x3 * (y1 * z2 - y2 * z1);

			// Находим компоненты нормалей к площадке
			float Nx = Ai / std::sqrtf(Ai * Ai + Bi * Bi + Ci * Ci);
			float Ny = -Bi / std::sqrtf(Ai * Ai + Bi * Bi + Ci * Ci);
			float Nz = -Ci / std::sqrtf(Ai * Ai + Bi * Bi + Ci * Ci);
			float Nt = Di / std::sqrtf(Ai * Ai + Bi * Bi + Ci * Ci + Di * Di);

			// Оисуем значения нормали по оси Х
			Uint8 Cx = (Nx + 1.f) * 127.f;
			int isPositive = (z1 >= 0) + (z2 >= 0) + (z3 >= 0);
			if (isPositive > 2) // больше половины значений положительные
				texture.SetPixel({ x, y }, SDL_Color{ Cx, 0, 0, 255 });
			else
				texture.SetPixel({ x, y }, SDL_Color{ 0, 0, Cx, 255 });
		}
	}

	texture.UpdateTexture();
}

