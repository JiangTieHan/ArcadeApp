#include "Circle.h"
#include "Utils.h"

Circle::Circle() : Circle(Vec2D::ZERO, 0)
{
}

Circle::Circle(const Vec2D& center, float radius) : mRadius(radius)
{
	mPoints.push_back(center);
}

bool Circle::Intersects(const Circle& other) const
{
	return other.GetCenterPoint().Distance(GetCenterPoint()) < other.GetRadius() + GetRadius();
}

bool Circle::ContainsPoint(const Vec2D& point) const
{
	return isLessThanOrEqual(point.Distance(GetCenterPoint()), mRadius);
}
