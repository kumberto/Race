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
	Scene(const Scene& scene) = delete;
	Scene& operator=(const Scene& scene) = delete;
	Scene(Scene&& scene) = delete;
	Scene& operator=(Scene&& scene) = delete;
	void KeyPressed(int btnCode);
	void UpdateF(float deltaTime);
	static const int getSpeed();

private:
	void moveOncomingCar();
	void cleanOncoming();
	bool checkLeftMove();
	bool checkRightMove();
	void createFrame();
	void checkCollisionCars();
	void moveRacing();
	void cleanRacing();
	
	RacingCar racing_;
	OncomingCar* oncomingCar_;
	static int speedCounter_;
	int speed_;
	bool collision_;
	bool pause_;
};

