#ifndef MICRO_H
#define MOTO_H
#include "Enemy.h"
class Micro :
	public Enemy
{
public:
	Micro();
	~Micro();
private:
	void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};

#endif