#include "stdafx.h"
#include "Car.h"


Car::Car() {}

Car::Car(magicNumbers::StripOfRoadway strip)
{
	initPartsOfCar(strip);
}

const CarBody & Car::getCarBody() const
{
	return carBody_;
}

const CarWheels & Car::getCarWheels() const
{
	return carWheels_;
}

void Car::setCarX(int number)
{
	carBody_.setCarBodyX(number);
	carWheels_.setCarWheelX(number);
}

void Car::setCarY(int number)
{
	carBody_.setCarBodyY(number);
	carWheels_.setCarWheelY(number);
}

void Car::initPartsOfCar(magicNumbers::StripOfRoadway strip)
{
	if (strip == magicNumbers::StripOfRoadway::LEFT_STRIP)
	{
		const_cast<CarBody&>(getCarBody()).initPartsOfCar(magicNumbers::valueXBodyLeftStrip,
			magicNumbers::valueYRearPartBody,
			magicNumbers::valueYPassengerSeatBody,
			magicNumbers::valueYDriverSeatBody,
			magicNumbers::valueYFrontPartBody);
		const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(magicNumbers::valueXLeftWheelsLeftStrip,
			magicNumbers::valueYFrontWheelsAllStrip,
			magicNumbers::valueXRightWheelsLeftStrip,
			magicNumbers::valueYBackWheelsAllStrip);
	}
	else if (strip == magicNumbers::StripOfRoadway::CENTRAL_STRIP)
	{
		const_cast<CarBody&>(getCarBody()).initPartsOfCar(magicNumbers::valueXBodyCentralStrip,
			magicNumbers::valueYRearPartBody,
			magicNumbers::valueYPassengerSeatBody,
			magicNumbers::valueYDriverSeatBody,
			magicNumbers::valueYFrontPartBody);
		const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(magicNumbers::valueXLeftWheelsCentralStrip,
			magicNumbers::valueYFrontWheelsAllStrip,
			magicNumbers::valueXRightWheelsCentralStrip,
			magicNumbers::valueYBackWheelsAllStrip);
	}
	else if (strip == magicNumbers::StripOfRoadway::RIGHT_STRIP)
	{
		const_cast<CarBody&>(getCarBody()).initPartsOfCar(magicNumbers::valueXBodyRightStrip,
			magicNumbers::valueYRearPartBody,
			magicNumbers::valueYPassengerSeatBody,
			magicNumbers::valueYDriverSeatBody,
			magicNumbers::valueYFrontPartBody);
		const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(magicNumbers::valueXLeftWheelsRightStrip,
			magicNumbers::valueYFrontWheelsAllStrip,
			magicNumbers::valueXRightWheelsRightStrip,
			magicNumbers::valueYBackWheelsAllStrip);
	}
}