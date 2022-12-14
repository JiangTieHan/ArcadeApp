#pragma once

#include "Excluder.h"
#include "Color.h"

class Ball;
class Screen;
class BoundaryEdge;

class Block : public Excluder
{
public:
	static const int UNBREAKABLE = -1;

	Block();
	void Init(const AARectangle& rect, int hp, const Color& outlineColor, const Color& fillColor);
	void Draw(Screen& screen);
	void Bounce(Ball& ball, const BoundaryEdge& edge);
	void ReduceHp();

	inline int GetHp() const { return mHp; }
	inline bool IsDestroyed() const { return mHp == 0; }
	inline const Color& GetOutlineColor() const { return mOutlineColor; }
	inline const Color& GetFillColor() const { return mFillColor; }

private:
	Color mOutlineColor;
	Color mFillColor;
	int mHp; // -1 means unbreakable
};