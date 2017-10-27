#pragma once
#include "CarBody.h"
#include "CarWheels.h"
#include "enum.cpp"
class OncomingCar
{
public:
	OncomingCar(StripOfRoadway strip);
	~OncomingCar();
	OncomingCar(const OncomingCar& oncomingCar) = delete;
	OncomingCar& operator=(const OncomingCar& oncomingCar) = delete;
	OncomingCar(OncomingCar&& oncomingCar) = delete;
	OncomingCar& operator=(OncomingCar&& oncomingCar) = delete;
	const CarBody& getCarBody() const;
	const CarWheels& getCarWheels() const;
	void setOncomingCar(int number);
private:
	void initPartsOfCar(StripOfRoadway strip);
	CarBody carBody_;
	CarWheels carWheels_;
};

