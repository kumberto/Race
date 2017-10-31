#include "stdafx.h"
#include "RacingCar.h"


RacingCar::RacingCar()
{
	createCar();
}

RacingCar::~RacingCar()
{
}

void RacingCar::setCar(int number)
{
	const_cast<CarBody&>(getCarBody()).setCarBodyX(number);
	const_cast<CarWheels&>(getCarWheels()).setCarWheelX(number);
}


void RacingCar::reset()
{
	createCar();
}

void RacingCar::createCar()
{
	const_cast<CarBody&>(getCarBody()).initPartsOfCar(25, 16, 17, 18, 19);
	const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(24, 17, 26, 19);
}
