#include "AARectangle.h"
#include "Utils.h"
#include <cmath>

AARectangle::AARectangle() : AARectangle(Vec2D::ZERO, Vec2D::ZERO)
{
}

AARectangle::AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height)
{
	mPoints.push_back(topLeft);
	mPoints.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1));
}

AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& botRight)
{
	mPoints.push_back(topLeft);
	mPoints.push_back(botRight);
}

float AARectangle::GetWidth() const
{
	return GetBotRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}

float AARectangle::GetHeight() const
{
	return GetBotRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

void AARectangle::MoveTo(const Vec2D& position)
{
	float width = GetWidth();
	float height = GetHeight();

	SetTopLeftPoint(position);
	SetBotRightPoint(Vec2D(position.GetX() + width - 1, position.GetY() + height - 1));
}

Vec2D AARectangle::GetCenterPoint() const
{
	return Vec2D(GetTopLeftPoint().GetX() + GetWidth() / 2.0f,
		GetTopLeftPoint().GetY() + GetHeight() / 2.0f);
}

bool AARectangle::Intersects(const AARectangle& other) const
{
	return !(other.GetBotRightPoint().GetX() < GetTopLeftPoint().GetX() ||
		other.GetTopLeftPoint().GetX() > GetBotRightPoint().GetX() ||
		other.GetBotRightPoint().GetY() < GetTopLeftPoint().GetY() ||
		other.GetTopLeftPoint().GetY() > GetBotRightPoint().GetY());
}

bool AARectangle::ContainsPoints(const Vec2D& point) const
{
	bool withinX = point.GetX() >= GetTopLeftPoint().GetX() && point.GetX() <= GetBotRightPoint().GetX();
	bool withinY = point.GetY() >= GetTopLeftPoint().GetY() && point.GetY() <= GetBotRightPoint().GetY();
	return withinX && withinY;
}

AARectangle AARectangle::InSet(const AARectangle& rect, Vec2D& insets)
{
	return AARectangle(rect.GetTopLeftPoint() + insets, 
		rect.GetWidth() - 2 * insets.GetX(), rect.GetHeight() - 2 * insets.GetY());
}

std::vector<Vec2D> AARectangle::GetPoints() const
{
	std::vector<Vec2D> points;

	points.push_back(mPoints[0]);
	points.push_back(Vec2D(mPoints[1].GetX(), mPoints[0].GetY()));
	points.push_back(mPoints[1]);
	points.push_back(Vec2D(mPoints[0].GetX(), mPoints[1].GetY()));

	return points;
}
