#pragma once

#include <iostream>

class Vec2D {
public:
	static const Vec2D ZERO;
	Vec2D() : Vec2D(0, 0) {}
	Vec2D(float x, float y) : mX(x), mY(y) {}

	float Mag2() const;
	float Mag() const;
	float Distance(const Vec2D& other) const;
	float Dot(const Vec2D& other) const;
	float AngleBetween(const Vec2D& other) const;

	Vec2D GetUnitVec() const;
	Vec2D& Normalize();
	Vec2D ProjectOnto(const Vec2D& other) const;
	Vec2D Reflect(const Vec2D& normalVec) const;

	void Rotate(float angle, const Vec2D& aroundPoint);
	Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const;

	inline void SetX(float x) { mX = x; }
	inline void SetY(float y) { mY = y; }
	inline float GetX() const { return mX; }
	inline float GetY() const { return mY; }

	bool operator== (const Vec2D& otherVec) const;
	bool operator!= (const Vec2D& otherVec) const;
	Vec2D operator- () const;
	Vec2D operator* (float scalar) const;
	Vec2D operator/ (float scalar) const;
	Vec2D operator+ (const Vec2D& other) const;
	Vec2D operator- (const Vec2D& other) const;
	Vec2D& operator*= (float scalar);
	Vec2D& operator/= (float scalar);
	Vec2D& operator+= (const Vec2D& other);
	Vec2D& operator-= (const Vec2D& other);
	float operator* (const Vec2D& other) const; // dot product

private:
	float mX, mY;
};

std::ostream& operator<< (std::ostream& output, const Vec2D& vec);
Vec2D operator* (float scalar, const Vec2D& vec);