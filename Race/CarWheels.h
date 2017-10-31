#ifndef CARWHEELS_H
#define CARWHEELS_H
#include "Point.h"
class CarWheels
{
	public:
		CarWheels();
		~CarWheels();
		CarWheels(const CarWheels& carWheels) = delete;
		CarWheels& operator=(const CarWheels& carWheels) = delete;
		CarWheels(CarWheels&& carWheels) = delete;
		CarWheels& operator=(CarWheels&& carWheels) = delete;
		const Point& getFrontRight() const;
		const Point& getFrontLeft() const;
		const Point& getBackRight() const;
		const Point& getBackLeft() const;
		void setCarWheelX(int number);
		void setCarWheelY(int number);
		void initPartsOfCar(int leftX, int frontY, int rightX, int backY);
	private:
		Point frontRight_;
		Point frontLeft_;
		Point backRight_;
		Point backLeft_;
};
#endif