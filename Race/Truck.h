#ifndef TRUCK_H
#define TRUCK_H
#include "Car.h"
#include "Enemy.h"
class Truck : public Enemy
{
	public:
		Truck(magicNumbers::StripOfRoadway strip, magicNumbers::DirectionMovement direction);
		~Truck();
	private:
		void checkAchievementRightEdge();
		void checkAchievementLeftEdge();
		bool achievementOfRightEdge;
		bool achievementOfLeftEdge;
		void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};

#endif