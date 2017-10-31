#include "stdafx.h"
#include "Point.h"
#include "MagicNumbers.h"



Point::Point(int x, int y)
: x_(x)
, y_(y)
{
}
 
int Point::getX() const
{
	return x_;
}

void Point::setX(int x)
{
	if (x == magicNumbers::rightMove || x == magicNumbers::leftMove) {
		x_ += x;
	}
	else {
		x_ = x;
	}
}

int Point::getY() const
{
	return y_;
}

void Point::setY(int y)
{
	if (y == magicNumbers::unitOfMovement) {
		y_ += y;
	}
	else {
		y_ = y;
	}
}
