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
		void reset();
		void setCheckLeftMove(bool check);
		void setCheckRightMove(bool check);
		void setCheckUpMove(bool check);
		void setCheckDownMove(bool check);
		bool checkLeftMove();
		bool checkRightMove();
		bool checkUpMove();
		bool checkDownMove();
	private:
		void createCar();
		bool checkLeftMove_;
		bool checkRightMove_;
		bool checkUpMove_;
		bool checkDownMove_;
};
#endif