#include <iostream>
#include "AppWindow.h"
#include "Examples.h"
#include "Functions.h"
#include "imgui.h"
#include "Texture.h"
#include "MImageCalculator.h"



float MyAwesomeFunction(SDL_Point arg)
{
	const SDL_Point circlePos1{ 300, 300 };
	const float circleRadius1 = 50;
	const SDL_Point circlePos2{ 100, 100 };
	const float circleRadius2 = 100;

	float c1 = Functions::Circle(circlePos1, circleRadius1, arg);
	float c2 = Functions::Circle(circlePos2, circleRadius2, arg);
	float res = Functions::ROr(c1, c2);

	return res;
}

class Window: public AppWindow
{
public:
	Window(SDL_Point windowSize) :
		AppWindow(windowSize),
		texture(GetRenderer(), windowSize),
		calculator(&MyAwesomeFunction) // передаем функцию которую будем рассчитывать
	{
		ComputeFunction();
	}

	void ComputeFunction()
	{
		std::vector<std::vector<MImageCalculator::MImagePixelData>> data = calculator.GetSpaceData(texture.GetSize());
		for (size_t i = 0; i < data.size(); ++i)
		{
			for (size_t j = 0; j < data[i].size(); ++j)
			{
				MImageCalculator::MImagePixelData mimageData = data[i][j];
				uint8_t colorValue = (mimageData.nx + 1.f) * 127.f;
				if (mimageData.zone == MImageCalculator::FunctionZone::Positive)
					texture.SetPixel(SDL_Point(i, j), SDL_Color{ colorValue, 0, 0, 255 });
				else if (mimageData.zone == MImageCalculator::FunctionZone::Negative)
					texture.SetPixel(SDL_Point(i, j), SDL_Color{ 0, 0, colorValue, 255 });
			}
		}
		texture.UpdateTexture();
	}

	void Render() override
	{
		texture.Render();
	}

	void RenderGui() override
	{
		ImGui::Begin("MyWindow");
		ImGui::End();
	}

	void ProcessEvent(const SDL_Event& e) override
	{

	}

	Texture texture;
	MImageCalculator calculator;
};


int main(int argc, char** argv)
{
	Window window({800, 600});
	
	window.Show();
	
	return 0;
}