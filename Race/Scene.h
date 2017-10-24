#pragma once
#include "ChangeConsole\BaseApp.h"
#include "RacingCar.h"
#include "OncomingCar.h"
#include "enum.cpp"
class Scene :
	public BaseApp
{

public:
	Scene();
	~Scene();
	void KeyPressed(int btnCode);
	void UpdateF(float deltaTime);
	void moveRacing();
	void cleanRacing();
	static const int getSpeed();

private:
	void moveOncomingCar();
	void cleanOncoming();
	bool checkLeftMove();
	bool checkRightMove();
	void createFrame();
	void checkCollisionCars();

	RacingCar racing_;
	OncomingCar* oncomingCar_;
	static int speedCounter_;
	int speed_;
	bool collision_;
	bool pause_;
};

