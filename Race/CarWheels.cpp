#include "stdafx.h"
#include "CarWheels.h"


CarWheels::CarWheels()
{
}


CarWheels::~CarWheels()
{
}

const Point & CarWheels::getFrontRight() const
{
	return static_cast<const Point&>(frontRight_);
}

const Point & CarWheels::getFrontLeft() const
{
	return static_cast<const Point&>(frontLeft_);
}

const Point & CarWheels::getBackRight() const
{
	return static_cast<const Point&>(backRight_);
}

const Point & CarWheels::getBackLeft() const
{
	return static_cast<const Point&>(backLeft_);
}

void CarWheels::setCarWheelX(int number)
{
	frontLeft_.setX(number);
	frontRight_.setX(number);
	backLeft_.setX(number);
	backRight_.setX(number);
}

void CarWheels::setCarWheelY(int number)
{
	frontLeft_.setY(number);
	frontRight_.setY(number);
	backLeft_.setY(number);
	backRight_.setY(number);
}

void CarWheels::initPartsOfCar(int leftX, int frontY, int rightX, int backY)
{
	frontLeft_.setX(leftX);
	frontLeft_.setY(frontY);
	frontRight_.setX(rightX);
	frontRight_.setY(frontY);
	backLeft_.setX(leftX);
	backLeft_.setY(backY);
	backRight_.setX(rightX);
	backRight_.setY(backY);
}
