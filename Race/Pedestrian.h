#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include "Enemy.h"
class Pedestrian :
	public Enemy
{
public:
	Pedestrian();
	~Pedestrian();
private:
	void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};

#endif