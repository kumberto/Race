#include "stdafx.h"
#include "Point.h"



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
	x_ += x;
}

int Point::getY() const
{
	return y_;
}

void Point::setY(int y)
{
	y_ += y;
}
