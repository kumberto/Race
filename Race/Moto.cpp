#include "stdafx.h"
#include "OncomingCar.h"


OncomingCar::OncomingCar(magicNumbers::StripOfRoadway strip)
: Car(strip)
{
}


OncomingCar::~OncomingCar()
{
}

void OncomingCar::move()
{
	setCarY(magicNumbers::unitOfMovement);
}
