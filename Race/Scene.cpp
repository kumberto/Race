#include "stdafx.h"
#include <time.h>
#include "Scene.h"

int Scene::speedCounter_ = 300;

Scene::Scene()
: BaseApp(50, 30)
, oncomingCar_(nullptr)
, speed_(49)
, collision_(false)
, pause_(false)
{
	createFrame();
}


Scene::~Scene()
{
}

void Scene::KeyPressed(int btnCode)
{
	if (btnCode == 80) //down
	{
		if (speedCounter_ < 300 && speed_ > 48)
		{
			speedCounter_ += 30;
			speed_ -= 1;
			SetChar(37, 6, speed_);
		}
	}
	else if (btnCode == 75) //left
	{
		if (checkLeftMove())
		{
			cleanRacing();
			racing_.setRacingCar(-1);
			moveRacing();
		}
	}
	else if (btnCode == 77) //right
	{
		if (checkRightMove())
		{
			cleanRacing();
			racing_.setRacingCar(1);
			moveRacing();
		}
	}
	else if (btnCode == 72)
	{
		if (speedCounter_ > 60 && speed_ < 58)
		{
			speedCounter_ -= 30;
			speed_ += 1;
			SetChar(37, 6, speed_);
		}
	}
	else if (btnCode == 13) 
	{
		if (pause_)
		{
			pause_ = false;
			SetChar(23, 12, ' ');
			SetChar(24, 12, ' ');
			SetChar(25, 12, ' ');
			SetChar(26, 12, ' ');
			SetChar(27, 12, ' ');
			moveRacing();
			moveOncomingCar();
		}
		else
		{
			pause_ = true;
		}
	}
	else if (btnCode == 27)
	{
		exit(0);
	}
}

void Scene::UpdateF(float deltaTime)
{
	srand(time(nullptr));
	int strip = 0;
	if (!pause_)
	{
		if (!collision_)
		{
			if (oncomingCar_ == nullptr)
			{
				strip = rand() % 3;
				OncomingCar* car = new OncomingCar((StripOfRoadway)strip);
				oncomingCar_ = car;
			}
			cleanOncoming();
			oncomingCar_->setOncomingCar(1);
			moveOncomingCar();
			checkCollisionCars();
			if (oncomingCar_->getCarBody().getFrontPartOfCar().getY() == 20)
			{
				OncomingCar* temp = oncomingCar_;
				oncomingCar_ = nullptr;
				delete temp;
			}
		}
		else {
			SetChar(21, 12, 'G');
			SetChar(22, 12, 'A');
			SetChar(23, 12, 'M');
			SetChar(24, 12, 'E');
			SetChar(26, 12, 'O');
			SetChar(27, 12, 'V');
			SetChar(28, 12, 'E');
			SetChar(29, 12, 'R');
		}
	}
	else
	{
		SetChar(23, 12, 'P');
		SetChar(24, 12, 'A');
		SetChar(25, 12, 'U');
		SetChar(26, 12, 'S');
		SetChar(27, 12, 'E');
	}
}

void Scene::moveRacing()
{
	SetChar(racing_.getCarBody().getFrontPartOfCar().getX(), racing_.getCarBody().getFrontPartOfCar().getY(), '+');
	SetChar(racing_.getCarBody().getDriverSeat().getX(), racing_.getCarBody().getDriverSeat().getY(), '+');
	SetChar(racing_.getCarBody().getPassengerSeat().getX(), racing_.getCarBody().getPassengerSeat().getY(), '+');
	SetChar(racing_.getCarBody().getRearPartOfCar().getX(), racing_.getCarBody().getRearPartOfCar().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontRight().getX(), racing_.getCarWheels().getFrontRight().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontLeft().getX(), racing_.getCarWheels().getFrontLeft().getY(), '+');
	SetChar(racing_.getCarWheels().getBackRight().getX(), racing_.getCarWheels().getBackRight().getY(), '+');
	SetChar(racing_.getCarWheels().getBackLeft().getX(), racing_.getCarWheels().getBackLeft().getY(), '+');
}

void Scene::moveOncomingCar()
{
	if (oncomingCar_->getCarBody().getFrontPartOfCar().getY() > 4 && oncomingCar_->getCarBody().getFrontPartOfCar().getY() < 20)
	{
		SetChar(oncomingCar_->getCarBody().getFrontPartOfCar().getX(), oncomingCar_->getCarBody().getFrontPartOfCar().getY(), '+');
	}
	if (oncomingCar_->getCarBody().getDriverSeat().getY() > 4 && oncomingCar_->getCarBody().getDriverSeat().getY() < 20)
	{
		SetChar(oncomingCar_->getCarWheels().getFrontRight().getX(), oncomingCar_->getCarWheels().getFrontRight().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getFrontLeft().getX(), oncomingCar_->getCarWheels().getFrontLeft().getY(), '+');
		SetChar(oncomingCar_->getCarBody().getDriverSeat().getX(), oncomingCar_->getCarBody().getDriverSeat().getY(), '+');
	}
	if (oncomingCar_->getCarBody().getPassengerSeat().getY() > 4 && oncomingCar_->getCarBody().getPassengerSeat().getY() < 20)
	{
		SetChar(oncomingCar_->getCarBody().getPassengerSeat().getX(), oncomingCar_->getCarBody().getPassengerSeat().getY(), '+');
	}
	if (oncomingCar_->getCarBody().getRearPartOfCar().getY() > 4 && oncomingCar_->getCarBody().getRearPartOfCar().getY() < 20)
	{
		SetChar(oncomingCar_->getCarBody().getRearPartOfCar().getX(), oncomingCar_->getCarBody().getRearPartOfCar().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getBackRight().getX(), oncomingCar_->getCarWheels().getBackRight().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getBackLeft().getX(), oncomingCar_->getCarWheels().getBackLeft().getY(), '+');
	}
}

void Scene::cleanRacing()
{
	SetChar(racing_.getCarBody().getFrontPartOfCar().getX(), racing_.getCarBody().getFrontPartOfCar().getY(), ' ');
	SetChar(racing_.getCarBody().getDriverSeat().getX(), racing_.getCarBody().getDriverSeat().getY(), ' ');
	SetChar(racing_.getCarBody().getPassengerSeat().getX(), racing_.getCarBody().getPassengerSeat().getY(), ' ');
	SetChar(racing_.getCarBody().getRearPartOfCar().getX(), racing_.getCarBody().getRearPartOfCar().getY(), ' ');
	SetChar(racing_.getCarWheels().getFrontRight().getX(), racing_.getCarWheels().getFrontRight().getY(), ' ');
	SetChar(racing_.getCarWheels().getFrontLeft().getX(), racing_.getCarWheels().getFrontLeft().getY(), ' ');
	SetChar(racing_.getCarWheels().getBackRight().getX(), racing_.getCarWheels().getBackRight().getY(), ' ');
	SetChar(racing_.getCarWheels().getBackLeft().getX(), racing_.getCarWheels().getBackLeft().getY(), ' ');
}

const int Scene::getSpeed()
{
	return speedCounter_;
}

void Scene::cleanOncoming()
{
	if (oncomingCar_->getCarBody().getFrontPartOfCar().getY() > 4 && oncomingCar_->getCarBody().getFrontPartOfCar().getY() < 20)
	{
		SetChar(oncomingCar_->getCarBody().getFrontPartOfCar().getX(), oncomingCar_->getCarBody().getFrontPartOfCar().getY(), ' ');
	}
	if (oncomingCar_->getCarBody().getDriverSeat().getY() > 4 && oncomingCar_->getCarBody().getDriverSeat().getY() < 20)
	{
		SetChar(oncomingCar_->getCarWheels().getFrontRight().getX(), oncomingCar_->getCarWheels().getFrontRight().getY(), ' ');
		SetChar(oncomingCar_->getCarWheels().getFrontLeft().getX(), oncomingCar_->getCarWheels().getFrontLeft().getY(), ' ');
		SetChar(oncomingCar_->getCarBody().getDriverSeat().getX(), oncomingCar_->getCarBody().getDriverSeat().getY(), ' ');
	}
	if (oncomingCar_->getCarBody().getPassengerSeat().getY() > 4 && oncomingCar_->getCarBody().getPassengerSeat().getY() < 20)
	{
		SetChar(oncomingCar_->getCarBody().getPassengerSeat().getX(), oncomingCar_->getCarBody().getPassengerSeat().getY(), ' ');
	}
	if (oncomingCar_->getCarBody().getRearPartOfCar().getY() > 4 && oncomingCar_->getCarBody().getRearPartOfCar().getY() < 20)
	{
		SetChar(oncomingCar_->getCarBody().getRearPartOfCar().getX(), oncomingCar_->getCarBody().getRearPartOfCar().getY(), ' ');
		SetChar(oncomingCar_->getCarWheels().getBackRight().getX(), oncomingCar_->getCarWheels().getBackRight().getY(), ' ');
		SetChar(oncomingCar_->getCarWheels().getBackLeft().getX(), oncomingCar_->getCarWheels().getBackLeft().getY(), ' ');
	}
}

void Scene::createFrame()
{
	for (int i = 4; i < 21; i++)
	{
		for (int j = 20; j < 31; j++)
		{
			if (i == 4 || j == 20 || i == 20 || j == 30) {
				SetChar(j, i, '#');
			}
		}
	}
	for (int i = 4; i < 9; i++)
	{
		for (int j = 31; j < 40; j++)
		{
			if (i == 4 || i == 8|| j == 39)
			{
				SetChar(j, i, '#');
			}
		}
	}
	SetChar(31, 6, 'S');
	SetChar(32, 6, 'p');
	SetChar(33, 6, 'e');
	SetChar(34, 6, 'e');
	SetChar(35, 6, 'd');
	SetChar(36, 6, ':');
	SetChar(37, 6, speed_);
	SetChar(racing_.getCarBody().getFrontPartOfCar().getX(), racing_.getCarBody().getFrontPartOfCar().getY(), '+');
	SetChar(racing_.getCarBody().getDriverSeat().getX(), racing_.getCarBody().getDriverSeat().getY(), '+');
	SetChar(racing_.getCarBody().getPassengerSeat().getX(), racing_.getCarBody().getPassengerSeat().getY(), '+');
	SetChar(racing_.getCarBody().getRearPartOfCar().getX(), racing_.getCarBody().getRearPartOfCar().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontRight().getX(), racing_.getCarWheels().getFrontRight().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontLeft().getX(), racing_.getCarWheels().getFrontLeft().getY(), '+');
	SetChar(racing_.getCarWheels().getBackRight().getX(), racing_.getCarWheels().getBackRight().getY(), '+');
	SetChar(racing_.getCarWheels().getBackLeft().getX(), racing_.getCarWheels().getBackLeft().getY(), '+');
}

void Scene::checkCollisionCars()
{
	if (GetChar(oncomingCar_->getCarWheels().getFrontRight().getX(), (oncomingCar_->getCarWheels().getFrontRight().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarWheels().getFrontLeft().getX(), (oncomingCar_->getCarWheels().getFrontLeft().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarBody().getRearPartOfCar().getX(), (oncomingCar_->getCarBody().getRearPartOfCar().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarWheels().getBackRight().getX(), (oncomingCar_->getCarWheels().getBackRight().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarWheels().getBackLeft().getX(), (oncomingCar_->getCarWheels().getBackLeft().getY() + 1)) == '+')
	{
		collision_ = true;
	}
}

bool Scene::checkLeftMove() {
	if (racing_.getCarWheels().getFrontLeft().getX() == 21)
	{
		return false;
	}
	return true;
}

bool Scene::checkRightMove() {
	if (racing_.getCarWheels().getFrontRight().getX() == 29)
	{
		return false;
	}
	return true;
}
