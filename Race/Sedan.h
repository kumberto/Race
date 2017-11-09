#ifndef SEDAN_H
#define SEDAN_H
#include "Enemy.h"
class Sedan :
	public Enemy
{
public:
	Sedan();
	~Sedan();
private:
	void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};

#endif