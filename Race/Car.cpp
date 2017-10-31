#include "stdafx.h"
#include "Car.h"


Car::Car()
{
}


Car::~Car()
{
}

const CarBody & Car::getCarBody() const
{
	return carBody_;
}

const CarWheels & Car::getCarWheels() const
{
	return carWheels_;
}

void Car::setCar(int number)
{
	carBody_.setCarBodyX(number);
	carWheels_.setCarWheelX(number);
}