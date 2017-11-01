#include "stdafx.h"
#include "RacingCar.h"
#include "MagicNumbers.h"


RacingCar::RacingCar()
:  Car()
, checkLeftMove_(true)
, checkRightMove_(true)
, checkUpMove_(true)
, checkDownMove_(true)
{
	createCar();
}

RacingCar::~RacingCar()
{
}

void RacingCar::reset()
{
	createCar();
}

void RacingCar::setCheckLeftMove(bool check)
{
	checkLeftMove_ = check;
}

void RacingCar::setCheckRightMove(bool check)
{
	checkRightMove_ = check;
}

void RacingCar::setCheckUpMove(bool check)
{
	checkUpMove_ = check;
}

void RacingCar::setCheckDownMove(bool check)
{
	checkDownMove_ = check;
}

void RacingCar::createCar()
{
	const_cast<CarBody&>(getCarBody()).initPartsOfCar(magicNumbers::valueXForConstructionBody,
													  magicNumbers::valueYForRearPartBody,
													  magicNumbers::valueYForPassengerBody,
													  magicNumbers::valueYForDriverSeatBody,
													  magicNumbers::valueYForFrontPartBody);
	const_cast<CarWheels&>(getCarWheels()).initPartsOfCar(magicNumbers::valueXLeftWheels,
														  magicNumbers::valueYFrontWheels,
														  magicNumbers::valueXRightWheels,
														  magicNumbers::valueYBackWheels);
}

bool RacingCar::checkLeftMove() {
	if (getCarWheels().getFrontLeft().getX() == magicNumbers::borderLeftSide) {
		checkLeftMove_ = false;
	}
	return checkLeftMove_;
}

bool RacingCar::checkRightMove() {
	if (getCarWheels().getFrontRight().getX() == magicNumbers::borderRightSide) {
		checkRightMove_ = false;
	}
	return checkRightMove_;
}

bool RacingCar::checkUpMove()
{
	if (getCarBody().getFrontPartOfCar().getY() == magicNumbers::borderTopSide) {
		checkUpMove_ = false;
	}
	return checkUpMove_;
}

bool RacingCar::checkDownMove()
{
	if (getCarBody().getRearPartOfCar().getY() == magicNumbers::borderBottonSide) {
		checkDownMove_ = false;
	}
	return checkDownMove_;
}

