#include "stdafx.h"
#include "CarBody.h"


CarBody::CarBody()
{
}

CarBody::~CarBody()
{
}

const Point & CarBody::getFrontPartOfCar() const
{
	return static_cast<const Point&>(frontPartOfCar_);
}

const Point & CarBody::getDriverSeat() const
{
	return static_cast<const Point&>(driverSeat_);
}

const Point & CarBody::getPassengerSeat() const
{
	return static_cast<const Point&>(passengerSeat_);
}

const Point & CarBody::getRearPartOfCar() const
{
	return static_cast<const Point&>(rearPartOfCar_);
}

void CarBody::setCarBodyX(int number)
{
	frontPartOfCar_.setX(number);
	driverSeat_.setX(number);
	passengerSeat_.setX(number);
	rearPartOfCar_.setX(number);
}

void CarBody::setCarBodyY(int number)
{
	frontPartOfCar_.setY(number);
	driverSeat_.setY(number);
	passengerSeat_.setY(number);
	rearPartOfCar_.setY(number);
}

void CarBody::initPartsOfCar(int x, int frontPartY, int driverSeatY, int passengerSeatY, int rearPartY)
{
	frontPartOfCar_.setX(x);
	frontPartOfCar_.setY(frontPartY);
	driverSeat_.setX(x);
	driverSeat_.setY(driverSeatY);
	passengerSeat_.setX(x);
	passengerSeat_.setY(passengerSeatY);
	rearPartOfCar_.setX(x);
	rearPartOfCar_.setY(rearPartY);
}
