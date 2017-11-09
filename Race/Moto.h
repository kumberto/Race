#ifndef ONCOMINGCAR_H
#define ONCOMINGCAR_H
#include "CarBody.h"
#include "CarWheels.h"
#include "MagicNumbers.h"
#include "Enemy.h"

class Moto : public Enemy
{
public:
	OncomingCar(magicNumbers::StripOfRoadway strip);
	~OncomingCar();
	void move();
private:
	void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};
#endif