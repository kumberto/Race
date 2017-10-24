#pragma once
#include "Point.h"

class CarBody
{
public:
	CarBody();
	~CarBody();
	const Point& getFrontPartOfCar() const;
	const Point& getDriverSeat() const;
	const Point& getPassengerSeat() const;
	const Point& getRearPartOfCar() const;
	void setCarBodyX(int number);
	void setCarBodyY(int number);
	void initPartsOfCar(int x, int frontPartY, int driverSeatY, int passengerSeatY, int rearPartY);
private:
	Point frontPartOfCar_;
	Point driverSeat_;
	Point passengerSeat_;
	Point rearPartOfCar_;
};

