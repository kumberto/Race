#include "stdafx.h"
#include "RacingCar.h"


RacingCar::RacingCar()
{
	createCar();
}


RacingCar::~RacingCar()
{
}

const CarBody & RacingCar::getCarBody() const
{
	return carBody_;
}

const CarWheels & RacingCar::getCarWheels() const
{
	return carWheels_;
}

void RacingCar::setRacingCar(int number)
{
	carBody_.setCarBodyX(number);
	carWheels_.setCarWheelX(number);
}

void RacingCar::createCar()
{
	carBody_.initPartsOfCar(25, 16, 17, 18, 19);
	carWheels_.initPartsOfCar(24, 17, 26, 19);
}
