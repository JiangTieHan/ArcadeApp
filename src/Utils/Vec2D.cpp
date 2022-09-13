#include "Vec2D.h"

std::ostream& operator<< (std::ostream& output, const Vec2D& vec)
{
	std::cout << "X: " << vec.GetX() << ", Y: " << vec.GetY();
	return output;
}