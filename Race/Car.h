#ifndef CAR_H
#define CAR_H
#include "CarBody.h"
#include "CarWheels.h"
#include "MagicNumbers.h"
class Car
{
	public:
		Car();
		Car(magicNumbers::StripOfRoadway strip);
		virtual~Car() = 0 {};
		Car(const Car& car) = delete;
		Car& operator=(const Car& car) = delete;
		Car(Car&& car) = delete;
		Car& operator=(Car&& car) = delete;
		virtual const CarBody& getCarBody() const;
		virtual const CarWheels& getCarWheels() const;
		virtual void setCarX(int number);
		virtual void setCarY(int number);
	private:
		CarBody carBody_;
		CarWheels carWheels_;
		void initPartsOfCar(magicNumbers::StripOfRoadway strip);
};
#endif