#include "Vec2D.h"
#include "Utils.h"
#include <assert.h>

const Vec2D Vec2D::ZERO = Vec2D(0, 0);

Vec2D operator*(float scalar, const Vec2D& vec)
{
	return vec * scalar;
}

std::ostream& operator<< (std::ostream& output, const Vec2D& vec)
{
	std::cout << "X: " << vec.GetX() << ", Y: " << vec.GetY();
	return output;
}

float Vec2D::Mag2() const
{
	return *this * (*this);
}

float Vec2D::Mag() const
{
	return sqrt(Mag2());
}

float Vec2D::Distance(const Vec2D& other) const
{
	return (*this - other).Mag();
}

float Vec2D::Dot(const Vec2D& other) const
{
	return *this * other;
}

float Vec2D::AngleBetween(const Vec2D& other) const
{
	int cosAngle = (*this * other) / (this->Mag() * other.Mag());
	return acosf(cosAngle);
}

Vec2D Vec2D::GetUnitVec() const
{
	if(Mag() > EPSILON) return *this / Mag();
	return Vec2D::ZERO;
}

Vec2D& Vec2D::Normalize()
{
	if (Mag() > EPSILON) *this /= Mag();
	return *this;
}

Vec2D Vec2D::ProjectOnto(const Vec2D& other) const
{
	Vec2D unitVec = other.GetUnitVec();
	if (unitVec == Vec2D::ZERO) return Vec2D::ZERO;
	return Dot(unitVec) * unitVec;
}

Vec2D Vec2D::Reflect(const Vec2D& normalVec) const
{
	Vec2D unitNormVec = normalVec.GetUnitVec();
	if (unitNormVec == Vec2D::ZERO) return Vec2D::ZERO;
	return *this - 2 * ProjectOnto(normalVec);
}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint)
{
	*this = RotationResult(angle, aroundPoint);
}

Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const
{
	float cosine = cosf(angle);
	float sine = sinf(angle);
	Vec2D thisVec(mX, mY);
	thisVec -= aroundPoint;

	float xRot = thisVec.GetX() * cosine - thisVec.GetY() * sine;
	float yRot = thisVec.GetX() * sine + thisVec.GetY() * cosine;

	Vec2D rot = Vec2D(xRot, yRot);
	return rot + aroundPoint;
}

bool Vec2D::operator==(const Vec2D& otherVec) const
{
	return isEqual(mX, otherVec.GetX()) && isEqual(mY, otherVec.GetY());
}

bool Vec2D::operator!=(const Vec2D& otherVec) const
{
	return !(*this == otherVec);
}

Vec2D Vec2D::operator-() const
{
	return Vec2D(-mX, -mY);
}

Vec2D Vec2D::operator*(float scalar) const
{
	return Vec2D(mX * scalar, mY * scalar);
}

Vec2D Vec2D::operator/(float scalar) const
{
	assert(fabsf(scalar) > EPSILON);

	return Vec2D(mX / scalar, mY / scalar);
}

Vec2D Vec2D::operator+(const Vec2D& other) const
{
	return Vec2D(mX + other.GetX(), mY + other.GetY());
}

Vec2D Vec2D::operator-(const Vec2D& other) const
{
	return Vec2D(mX - other.GetX(), mY - other.GetY());
}

Vec2D& Vec2D::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

Vec2D& Vec2D::operator/=(float scalar)
{
	assert(fabsf(scalar) > EPSILON);

	*this = *this / scalar;
	return *this;
}

Vec2D& Vec2D::operator+=(const Vec2D& other)
{
	*this = *this + other;
	return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& other)
{
	*this = *this - other;
	return *this;
}

float Vec2D::operator*(const Vec2D& other) const
{
	return mX * other.GetX() + mY * other.GetY();
}
