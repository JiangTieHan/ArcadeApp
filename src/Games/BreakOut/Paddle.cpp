#include "Paddle.h"
#include "Ball.h"
#include "Screen.h"
#include "Utils.h"
#include "BoundaryEdge.h"
#include <assert.h>

const float Paddle::VELOCITT = 125.0f;
const float Paddle::CORNER_BOUNCE_AMT = 0.2f;
const uint32_t Paddle::PADDLE_WIDTH = 40;
const uint32_t Paddle::PADDLE_HEIGHT = 4;

void Paddle::Init(const AARectangle& rect, const AARectangle& boundary)
{
	Excluder::Init(rect);
	mBoundary = boundary;
	mDirection = 0;
}

void Paddle::Update(uint32_t dt, Ball& ball)
{
	if (GetAARectangle().ContainsPoints(ball.GetPosition()))
	{
		Vec2D pointOnEdge;
		ball.MakeFlushWithEdge(GetEdge(BOTTOM_EDGE), pointOnEdge, true);
	}

	if (mDirection != 0)
	{
		Vec2D dir;
		if ((mDirection & PaddleDirection::LEFT) == PaddleDirection::LEFT &&
			(mDirection & PaddleDirection::RIGHT) == PaddleDirection::RIGHT)
		{
			dir = Vec2D::ZERO;
		}
		else if (mDirection == PaddleDirection::LEFT)
		{
			dir = LEFT_DIR;
		}
		else
		{
			dir = RIGHT_DIR;
		}

		Vec2D dx = dir * VELOCITT * MillisecondToSeconds(dt);
		MoveBy(dx);

		const AARectangle& aaRect = GetAARectangle();
		if (isGreaterThanOrEqual(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetX()))
		{
			MoveTo(Vec2D(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetY()));
		}
		else if(isGreaterThanOrEqual(aaRect.GetBotRightPoint().GetX(), mBoundary.GetBotRightPoint().GetX()))
		{
			MoveTo(Vec2D(mBoundary.GetBotRightPoint().GetX() - aaRect.GetWidth(), aaRect.GetTopLeftPoint().GetY()));
		}
	}
}

void Paddle::Draw(Screen& screen)
{
	screen.Draw(GetAARectangle(), Color::Blue(), true, Color::Blue());
}

bool Paddle::Bounce(Ball& ball)
{
	BoundaryEdge edge;
	if (HasCollided(ball.GetBoundingRect(), edge))
	{
		Vec2D pointOnEdge;
		ball.MakeFlushWithEdge(edge, pointOnEdge, true);

		if (edge.edge == GetEdge(TOP_EDGE).edge)
		{
			float edgeLength = edge.edge.Length();
			assert(!isEqual(edgeLength, 0.0f));
			float tx = (pointOnEdge.GetX() - edge.edge.GetP0().GetX()) / edgeLength;

			if ((tx <= CORNER_BOUNCE_AMT) && ball.GetVelocity().GetX() > 0 ||
				(tx >= (1.0f - CORNER_BOUNCE_AMT) && ball.GetVelocity().GetX() < 0))
			{
				ball.SetVelocity(-ball.GetVelocity());
				return true;
			}
		}

		ball.SetVelocity(ball.GetVelocity().Reflect(edge.normal));
		return true;
	}

	return false;
}
