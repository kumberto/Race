#pragma once
#include "CarBody.h"
#include "CarWheels.h"
class RacingCar
{
	public:
		RacingCar();
		~RacingCar();
		RacingCar(const RacingCar& racingCar) = delete;
		RacingCar& operator=(const RacingCar& racingCar) = delete;
		RacingCar(RacingCar&& racingCar) = delete;
		RacingCar& operator=(RacingCar&& racingCar) = delete;
		const CarBody& getCarBody() const;
		const CarWheels& getCarWheels() const;
		void setRacingCar(int number);
	private:
		void createCar();
		CarBody carBody_;
		CarWheels carWheels_;
};

