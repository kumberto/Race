#ifndef SCENE_H
#define SCENE_H
#include "ChangeConsole\BaseApp.h"
#include "RacingCar.h"
#include "OncomingCar.h"
#include "MagicNumbers.h"
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
	void keyPressed(const int btnCode);
	void updateGameField(float deltaTime);
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
	void reset();
	
	RacingCar racing_;
	OncomingCar* oncomingCar_;
	static int speedCounter_;
	int speed_;
	bool collision_;
	bool pause_;
	bool checkLeftMove_;
	bool checkRightMove_;
};

#endif