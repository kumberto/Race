#include "stdafx.h"
#include "OncomingCar.h"


OncomingCar::OncomingCar(magicNumbers::StripOfRoadway strip)
{
	initPartsOfCar(strip);
}


OncomingCar::~OncomingCar()
{
}

void OncomingCar::setCar(int number)
{
	const_cast<CarBody&>(getCarBody()).setCarBodyY(number);
	const_cast<CarWheels&>(getCarWheels()).setCarWheelY(number);
}


void OncomingCar::initPartsOfCar(magicNumbers::StripOfRoadway strip)
{
	if (strip == magicNumbers::StripOfRoadway::LEFT_STRIP)
	{
		const_cast<CarBody&>(getCarBody()).initPartsOfCar(22, 0, 1, 2, 3);
		const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(23, 1, 21, 3);
	}
	else if (strip == magicNumbers::StripOfRoadway::CENTRAL_STRIP)
	{
		const_cast<CarBody&>(getCarBody()).initPartsOfCar(25, 0, 1, 2, 3);
		const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(26, 1, 24, 3);
	}
	else if (strip == magicNumbers::StripOfRoadway::RIGHT_STRIP)
	{
		const_cast<CarBody&>(getCarBody()).initPartsOfCar(28, 0, 1, 2, 3);
		const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(29, 1, 27, 3);
	}
}
