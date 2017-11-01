#ifndef CARBODY_H
#define CARBODY_H
#include "Point.h"

class CarBody
{
public:
	CarBody();
	~CarBody();
	CarBody(const CarBody& carBody) = delete;
	CarBody& operator=(const CarBody& carBody) = delete;
	CarBody(CarBody&& carBody) = delete;
	CarBody& operator=(CarBody&& carBody) = delete;
	const Point& getFrontPartOfCar() const;
	const Point& getDriverSeat() const;
	const Point& getPassengerSeat() const;
	const Point& getRearPartOfCar() const;
	void setCarBodyX(int number);
	void setCarBodyY(int number);
	void initPartsOfCar(int x, int rearPartY, int passengerSeatY, int driverSeatY, int frontPartY);
private:
	Point frontPartOfCar_;
	Point driverSeat_;
	Point passengerSeat_;
	Point rearPartOfCar_;
};

#endif