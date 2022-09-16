#include "App.h"
#include <SDL.h>
#include "Screen.h";
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "ArcadeScene.h"


App& App::Singleton()
{
	static App theApp;
	return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	mnoptrWindow = mScreen.Init(width, height, mag);
	return mnoptrWindow != nullptr;
}

void App::Run()
{
	if (mnoptrWindow)
	{
		Circle circle(Vec2D(mScreen.Width() / 2.0f, mScreen.Height() / 2.0f), 50.0f);
		Triangle triangle(Vec2D(50, 50), Vec2D(100, 30), Vec2D(25, 100));
		AARectangle rect(Vec2D(150, 30), Vec2D(200, 200));

		SDL_Event sdlEvent;
		bool running = true;

		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;
		uint32_t dt = 10;
		uint32_t accumulator = 0;

		std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
		arcadeScene->Init();

		while (running)
		{
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;
			if (frameTime > 300) frameTime = 300;
			lastTick = currentTick;

			accumulator += frameTime;

			// Input
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

			// Update
			while (accumulator >= dt)
			{
				// update current scene by dt;
				arcadeScene->Update(dt);
				std::cout << "Delta time step: " << dt << std::endl;

				accumulator -= dt;
			}

			// Render
			arcadeScene->Draw(mScreen);
			mScreen.SwapScreen();
		}
	}
}
