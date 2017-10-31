#ifndef CAR_H
#define CAR_H
#include "CarBody.h"
#include "CarWheels.h"
class Car
{
	public:
		Car();
		virtual~Car();
		Car(const Car& car) = delete;
		Car& operator=(const Car& car) = delete;
		Car(Car&& car) = delete;
		Car& operator=(Car&& car) = delete;
		virtual const CarBody& getCarBody() const;
		virtual const CarWheels& getCarWheels() const;
		virtual void setCar(int number) = 0;
	private:
		CarBody carBody_;
		CarWheels carWheels_;
};
#endif