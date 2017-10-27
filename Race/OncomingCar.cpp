#include "stdafx.h"
#include "OncomingCar.h"


OncomingCar::OncomingCar(StripOfRoadway strip)
{
	initPartsOfCar(strip);
}


OncomingCar::~OncomingCar()
{
}

const CarBody & OncomingCar::getCarBody() const
{
	return carBody_;
}

const CarWheels & OncomingCar::getCarWheels() const
{
	return carWheels_;
}
void OncomingCar::setOncomingCar(int number)
{
	carBody_.setCarBodyY(number);
	carWheels_.setCarWheelY(number);
}

void OncomingCar::initPartsOfCar(StripOfRoadway strip)
{
	if (strip == StripOfRoadway::LEFT_STRIP)
	{
		carBody_.initPartsOfCar(22, 0, 1, 2, 3);
		carWheels_.initPartsOfCar(23, 1, 21, 3);
	}
	else if (strip == StripOfRoadway::CENTRAL_STRIP)
	{
		carBody_.initPartsOfCar(25, 0, 1, 2, 3);
		carWheels_.initPartsOfCar(26, 1, 24, 3);
	}
	else if (strip == StripOfRoadway::RIGHT_STRIP)
	{
		carBody_.initPartsOfCar(28, 0, 1, 2, 3);
		carWheels_.initPartsOfCar(29, 1, 27, 3);
	}
}
