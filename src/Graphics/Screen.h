#pragma once
#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"

struct SDL_Window;
struct SDL_Surface;
class Vec2D;

class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
	void SwapScreen();

	inline void SetClearColor(const Color& clearColor) { mClearColor = clearColor; }
	inline uint32_t Width() const { return mWidth; }
	inline uint32_t Height() const { return mHeight; }

	//Draw functions go here
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);

private:
	Screen(const Screen& screen);
	Screen& operator= (const Screen& screen);

	uint32_t mWidth;
	uint32_t mHeight;

	Color mClearColor;
	ScreenBuffer mBackBuffer;

	SDL_Window* moptrWindow;
	SDL_Surface* mnoptrWindowSurface;

	void ClearScreen();
};