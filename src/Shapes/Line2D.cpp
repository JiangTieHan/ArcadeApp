#include "Line2D.h"
#include "Utils.h"
#include <cmath>

Line2D::Line2D() : mP0(Vec2D::ZERO), mP1(Vec2D::ZERO)
{
}

Line2D::Line2D(float x0, float y0, float x1, float y1) : mP0(Vec2D(x0, y0)), mP1(Vec2D(x1, y1))
{
}

Line2D::Line2D(const Vec2D& p0, const Vec2D& p1) : mP0(p0), mP1(p1)
{
}

bool Line2D::operator==(const Line2D& other) const
{
	return mP0 == other.mP0 && mP1 == other.mP1;
}

bool Line2D::operator!=(const Line2D& other) const
{
	return !(*this == other);
}

float Line2D::MinDistanceFrom(const Vec2D& p, bool limitToSegment) const
{
	return p.Distance(ClosesPoint(p, limitToSegment));
}

Vec2D Line2D::ClosesPoint(const Vec2D& p, bool limitToSegment) const
{
	Vec2D p0ToP = p - mP0;
	Vec2D p0ToP1 = mP1 - mP0;
	float l2 = p0ToP1.Mag2();
	float dot = p0ToP.Dot(p0ToP1);
	float t = dot / l2;

	if (limitToSegment)
	{
		t = std::fmax(0, std::fmin(1.0f, t));
	}

	return mP0 + p0ToP1 * t;
}

Vec2D Line2D::Midpoint() const
{
	return Vec2D((mP0.GetX() + mP1.GetX()) / 2.0f, (mP0.GetY() + mP1.GetY()) / 2.0f);
}

float Line2D::Slope() const
{
	float dx = mP1.GetX() - mP0.GetX();
	if (fabsf(dx) < EPSILON)
	{
		return 0.0f;
	}

	float dy = mP1.GetY() - mP1.GetY();
	return dy / dx;
}

float Line2D::Length() const
{
	return mP1.Distance(mP0);
}
