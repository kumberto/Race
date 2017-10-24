#pragma once
#include "CarBody.h"
#include "CarWheels.h"
#include "enum.cpp"
class OncomingCar
{
public:
	OncomingCar(StripOfRoadway strip);
	~OncomingCar();
	const CarBody& getCarBody() const;
	const CarWheels& getCarWheels() const;
	void setOncomingCar(int number);
private:
	void initPartsOfCar(StripOfRoadway strip);
	CarBody carBody_;
	CarWheels carWheels_;
};

