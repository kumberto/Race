#ifndef ONCOMINGCAR_H
#define ONCOMINGCAR_H
#include "Car.h"
#include "CarBody.h"
#include "CarWheels.h"
#include "MagicNumbers.h"
class OncomingCar : public Car
{
public:
	OncomingCar(magicNumbers::StripOfRoadway strip);
	~OncomingCar();
	void setCar(int number);
private:
	void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};
#endif