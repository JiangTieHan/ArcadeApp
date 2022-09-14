#include "Line2D.h"
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
	return 0.0f;
}

Vec2D Line2D::ClosesPoint(const Vec2D& p, bool limitToSegment) const
{
	return Vec2D();
}

Vec2D Line2D::Midpoint() const
{
	return Vec2D();
}

float Line2D::Slope() const
{
	return 0.0f;
}

float Line2D::Length() const
{
	return 0.0f;
}
