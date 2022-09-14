#pragma once
#include "Shape.h"

class AARectangle : public Shape
{
public:
	AARectangle();
	AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height);
	AARectangle(const Vec2D& topLeft, const Vec2D& botRight);

	inline void SetTopLeftPoint(const Vec2D& topLeft) { mPoints[0] = topLeft; }
	inline void SetBotRightPoint(const Vec2D& botRight) { mPoints[1] = botRight; }

	inline Vec2D GetTopLeftPoint() const { return mPoints[0]; }
	inline Vec2D GetBotRightPoint() const { return mPoints[1]; }

	float GetWidth() const;
	float GetHeight() const;

	void MoveTo(const Vec2D& position);
	virtual Vec2D GetCenterPoint() const override;

	bool Intersects(const AARectangle& other) const;
	bool ContainsPoints(const Vec2D& point) const;

	static AARectangle InSet(const AARectangle& rect, Vec2D& insets);

	virtual std::vector<Vec2D> GetPoints() const override;
};