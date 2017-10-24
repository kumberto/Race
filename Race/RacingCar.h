#pragma once
#include "CarBody.h"
#include "CarWheels.h"
class RacingCar
{
	public:
		RacingCar();
		~RacingCar();
		const CarBody& getCarBody() const;
		const CarWheels& getCarWheels() const;
		void setRacingCar(int number);
	private:
		void createCar();
		CarBody carBody_;
		CarWheels carWheels_;
};

