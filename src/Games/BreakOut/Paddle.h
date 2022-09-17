#pragma once

#include "Excluder.h"
#include <stdint.h>

class Screen;
class Ball;

enum PaddleDirection
{
	LEFT = 1 << 0,
	RIGHT = 1 << 2
};

class Paddle : public Excluder
{
public:
	static const uint32_t PADDLE_WIDTH, PADDLE_HEIGHT;
	void Init(const AARectangle& rect, const AARectangle& boundary);
	void Update(uint32_t dt, Ball& ball);
	void Draw(Screen& screen);
	bool Bounce(Ball& ball);

	inline bool IsMovingLeft() const { return mDirection == PaddleDirection::LEFT; }
	inline bool isMovingRight() const { return mDirection == PaddleDirection::RIGHT; }
	inline void StopMovement() { mDirection = 0; }
	inline void SetMovementDirection(PaddleDirection dir) { mDirection |= dir; }
	inline void UnsetMovementDirection(PaddleDirection dir) { mDirection &= ~dir; }

private:
	uint32_t mDirection;
	AARectangle mBoundary;
	static const float VELOCITT;
	static const float CORNER_BOUNCE_AMT;
};