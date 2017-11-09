#include "stdafx.h"
#include "Truck.h"
#include "MagicNumbers.h"


Truck::Truck(magicNumbers::StripOfRoadway strip, magicNumbers::DirectionMovement direction)
: Enemy(strip, direction)
, achievementOfLeftEdge(false)
, achievementOfRightEdge(false)
{
}


Truck::~Truck()
{
}

void Truck::move()
{
	
	if (!achievementOfRightEdge) {
		setCarX(magicNumbers::rightMove);
		setCarY(magicNumbers::downMove);
		checkAchievementRightEdge();
	}
	else if (!achievementOfLeftEdge) {
		setCarX(magicNumbers::leftMove);
		setCarY(magicNumbers::downMove);
		checkAchievementLeftEdge();
	}
}

void Truck::checkAchievementRightEdge()
{
	if (getCarWheels().getFrontRight().getX() == magicNumbers::borderRightSide) {
		achievementOfRightEdge = true;
		achievementOfLeftEdge = false;
	}

}

void Truck::checkAchievementLeftEdge()
{
	if (getCarWheels().getFrontLeft().getX() == magicNumbers::borderLeftSide) {
		achievementOfRightEdge = false;
		achievementOfLeftEdge = true;
	}
}
