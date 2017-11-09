#ifndef SCENE_H
#define SCENE_H
#include "ChangeConsole\BaseApp.h"
#include "RacingCar.h"
#include "Enemy.h"
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
	void drawEnemyCar();
	void cleanOncoming();
	void createFrame();
	void checkCollisionCars();
	void drawRacingCar();
	void cleanRacing();
	void reset();
	
	RacingCar racing_;
	Enemy* oncomingCar_;
	static int speedCounter_;
	int speed_;
	bool collision_;
	bool pause_;
};

#endif