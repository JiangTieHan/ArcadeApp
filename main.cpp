#include <SDL.h>
#include "Screen.h";
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;

int main(int argc, char* argv[])
{
	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

	Circle circle(Vec2D(theScreen.Width() / 2.0f, theScreen.Height() / 2.0f), 50.0f);
	theScreen.Draw(circle, Color::Pink());
	theScreen.SwapScreen();

	SDL_Event sdlEvent;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			default:
				break;
			}
		}
	}
	return 0;
}