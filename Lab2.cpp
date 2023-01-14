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
		if (ImGui::Button("Lab2"))
			lab2(texture);

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