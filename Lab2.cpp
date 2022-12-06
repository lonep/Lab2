#include <iostream>
#include "AppWindow.h"
#include "Examples.h"
#include "Functions.h"
#include "imgui.h"
#include "Texture.h"



class Window: public AppWindow
{
public:
	Window(SDL_Point windowSize):
		AppWindow(windowSize),
		texture(GetRenderer(), windowSize)
	{
	}
	
	void Render() override
	{
		texture.Render();
	}
	
	void RenderGui() override
	{
		ImGui::Begin("MyWindow");
		if (ImGui::Button("Kotiy example 1"))
			Kotiy_Exmaple1(texture);
		if (ImGui::Button("Kotiy example 2"))
			Kotiy_Exmaple2(texture);

		if (ImGui::Button("inside red"))
			colorData.setInsideMode(ColorData::red);

		if (ImGui::Button("inside blue"))
			colorData.setInsideMode(ColorData::blue);

		if (ImGui::Button("inside green"))
			colorData.setInsideMode(ColorData::green);

		if (ImGui::Button("outside red"))
			colorData.setOutsideMode(ColorData::red);

		if (ImGui::Button("outside blue"))
			colorData.setOutsideMode(ColorData::blue);

		if (ImGui::Button("outside green"))
			colorData.setOutsideMode(ColorData::green);
		

		ImGui::End();
	}
	
	void ProcessEvent(const SDL_Event& e) override
	{
		
	}
	
	Texture texture;
};


int main(int argc, char** argv)
{
	Window window({800, 600});
	
	window.Show();
	
	return 0;
}