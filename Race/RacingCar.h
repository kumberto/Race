#ifndef RACINGCAR_H
#define RACINGCAR_H
#include "Car.h"
#include "CarBody.h"
#include "CarWheels.h"
class RacingCar : public Car
{
	public:
		RacingCar();
		~RacingCar();
		void setCar(int number);
		void reset();
	private:
		void createCar();
};
#endif