#ifndef IENEMY_H
#define IENEMY_H

#include "MagicNumbers.h"
#include "ChangeConsole\BaseApp.h"
#include "CarBody.h"
#include "CarWheels.h"
class Enemy :  public BaseApp
{
	public:
		Enemy(magicNumbers::StripOfRoadway strip, magicNumbers::DirectionMovement direction);
		Enemy(const Enemy& enemy) = delete;
		Enemy(Enemy&& enemy) = delete;
		Enemy& operator=(const Enemy& enemy) = delete;
		Enemy& operator=(Enemy&& enemy) = delete;
		virtual ~Enemy() = 0;
		void move();
		virtual const CarBody& getCarBody() const;
		virtual const CarWheels& getCarWheels() const;
		virtual void setCarX(int number);
		virtual void setCarY(int number);
	private:
		void drawEnemy();
		void initPartsOfCar(magicNumbers::StripOfRoadway strip) = 0;
		void moveDiagonally();
		void moveLeft();
		void moveRight();
		void moveDown();

		magicNumbers::StripOfRoadway strip_;
		magicNumbers::DirectionMovement direction_;
		CarBody carBody_;
		CarWheels carWheels_;
};
#endif
