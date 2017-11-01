#include "stdafx.h"
#include <ctime>
#include "Scene.h"

int Scene::speedCounter_ = magicNumbers::lowerCounterLimitSpeed;

Scene::Scene()
: BaseApp(magicNumbers::widthApp, magicNumbers::heightApp)
, oncomingCar_(nullptr)
, speed_(magicNumbers::startingSpeed)
, collision_(false)
, pause_(false)
{
	createFrame();
}


Scene::~Scene()
{
}

void Scene::keyPressed(const int btnCode)
{
	if (btnCode == magicNumbers::leftKey && !pause_) {//left
		if (racing_.checkLeftMove() && !collision_) {
			cleanRacing();
			racing_.setCarX(magicNumbers::leftMove);
			drawRacingCar();
			racing_.setCheckRightMove(true);
		}
	}
	else if (btnCode == magicNumbers::rightKey && !pause_) {//right
		if (racing_.checkRightMove() && !collision_) {
			cleanRacing();
			racing_.setCarX(magicNumbers::rightMove);
			drawRacingCar();
			racing_.setCheckLeftMove(true);
		}
	}
	else if (btnCode == magicNumbers::upKey && !pause_) {
		if (racing_.checkUpMove() && !collision_) {
			cleanRacing();
			racing_.setCarY(-1);
			drawRacingCar();
			racing_.setCheckDownMove(true);
		}
	}
	else if (btnCode == magicNumbers::downKey && !pause_) {
		if (racing_.checkDownMove() && !collision_) {
			cleanRacing();
			racing_.setCarY(1);
			drawRacingCar();
			racing_.setCheckUpMove(true);
		}
	}
	else if (btnCode == magicNumbers::speedUpKey && !pause_) {
		if (speedCounter_ > magicNumbers::upperCounterLimitSpeed &&
			speed_ < magicNumbers::upperSpeedLimit && !collision_) {
			speedCounter_ -= magicNumbers::stepCounter;
			speed_ += magicNumbers::stepSpeed;
			SetChar(magicNumbers::drawOfSpeedByX, magicNumbers::drawOfSpeedByY, speed_);
		}
	}
	else if (btnCode == magicNumbers::speedDownKey && !pause_) { //down
		if (speedCounter_ < magicNumbers::lowerCounterLimitSpeed &&
			speed_ > magicNumbers::lowerSpeedLimit && !collision_)
		{
			speedCounter_ += magicNumbers::stepCounter;
			speed_ -= magicNumbers::stepSpeed;
			SetChar(magicNumbers::drawOfSpeedByX, magicNumbers::drawOfSpeedByY, speed_);
		}
	}
	else if (btnCode == magicNumbers::enterKey && !collision_) {
		if (pause_) {
			pause_ = false;
			SetChar(magicNumbers::drawOfPByX, magicNumbers::drawOfPauseByY, ' ');
			SetChar(magicNumbers::drawOfAByX, magicNumbers::drawOfPauseByY, ' ');
			SetChar(magicNumbers::drawOfUByX, magicNumbers::drawOfPauseByY, ' ');
			SetChar(magicNumbers::drawOfSByX, magicNumbers::drawOfPauseByY, ' ');
			SetChar(magicNumbers::drawOfEByX, magicNumbers::drawOfPauseByY, ' ');
			drawRacingCar();
			drawEnemyCar();
		}
		else {
			pause_ = true;
		}
	}
	else if (btnCode == magicNumbers::exitKey) {
		exit(0);
	}
	else if (btnCode == magicNumbers::resetKey) {
		reset();
	}
}

void Scene::updateGameField(float deltaTime)
{
	srand(time(nullptr));
	int strip = 0;
	if (!pause_) {
		if (!collision_) {
			if (oncomingCar_ == nullptr) {
				strip = rand() % magicNumbers::quantityStrips;
				DiagonallyMove* car = new DiagonallyMove(static_cast<magicNumbers::StripOfRoadway>(strip));
				oncomingCar_ = car;
			}
			cleanOncoming();
			drawRacingCar();
			checkCollisionCars();
			oncomingCar_->move();
			drawEnemyCar();
			if (oncomingCar_->getCarBody().getRearPartOfCar().getY() == magicNumbers::endMoveOncomingCar) {
				DiagonallyMove* temp = oncomingCar_;
				oncomingCar_ = nullptr;
				delete temp;
			}
		}
		else {
			SetChar(magicNumbers::drawOfGGameOverByX, magicNumbers::drawOfGameOverByY, 'G');
			SetChar(magicNumbers::drawOfAGameOverByX, magicNumbers::drawOfGameOverByY, 'A');
			SetChar(magicNumbers::drawOfMGameOverByX, magicNumbers::drawOfGameOverByY, 'M');
			SetChar(magicNumbers::drawOfEGameOverByX, magicNumbers::drawOfGameOverByY, 'E');
			SetChar(magicNumbers::drawOfOGameOverByX, magicNumbers::drawOfGameOverByY, 'O');
			SetChar(magicNumbers::drawOfVGameOverByX, magicNumbers::drawOfGameOverByY, 'V');
			SetChar(magicNumbers::drawOfEEGameOverByX, magicNumbers::drawOfGameOverByY, 'E');
			SetChar(magicNumbers::drawOfRGameOverByX, magicNumbers::drawOfGameOverByY, 'R');
		}
	}
	else if (!collision_) {
		SetChar(magicNumbers::drawOfPByX, magicNumbers::drawOfPauseByY, 'P');
		SetChar(magicNumbers::drawOfAByX, magicNumbers::drawOfPauseByY, 'A');
		SetChar(magicNumbers::drawOfUByX, magicNumbers::drawOfPauseByY, 'U');
		SetChar(magicNumbers::drawOfSByX, magicNumbers::drawOfPauseByY, 'S');
		SetChar(magicNumbers::drawOfEByX, magicNumbers::drawOfPauseByY, 'E');
	}
}

void Scene::drawRacingCar()
{
	SetChar(racing_.getCarBody().getFrontPartOfCar().getX(),
		racing_.getCarBody().getFrontPartOfCar().getY(), '+');
	SetChar(racing_.getCarBody().getDriverSeat().getX(),
		racing_.getCarBody().getDriverSeat().getY(), '+');
	SetChar(racing_.getCarBody().getPassengerSeat().getX(),
		racing_.getCarBody().getPassengerSeat().getY(), '+');
	SetChar(racing_.getCarBody().getRearPartOfCar().getX(),
		racing_.getCarBody().getRearPartOfCar().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontRight().getX(),
		racing_.getCarWheels().getFrontRight().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontLeft().getX(),
		racing_.getCarWheels().getFrontLeft().getY(), '+');
	SetChar(racing_.getCarWheels().getBackRight().getX(),
		racing_.getCarWheels().getBackRight().getY(), '+');
	SetChar(racing_.getCarWheels().getBackLeft().getX(),
		racing_.getCarWheels().getBackLeft().getY(), '+');
}

void Scene::drawEnemyCar()
{
	if (oncomingCar_->getCarBody().getFrontPartOfCar().getY() > magicNumbers::beginMoveOncomingCar &&
		oncomingCar_->getCarBody().getFrontPartOfCar().getY() < magicNumbers::endMoveOncomingCar)
	{
		SetChar(oncomingCar_->getCarBody().getFrontPartOfCar().getX(),
			oncomingCar_->getCarBody().getFrontPartOfCar().getY(), '+');
	}
	if (oncomingCar_->getCarBody().getDriverSeat().getY() > magicNumbers::beginMoveOncomingCar &&
		oncomingCar_->getCarBody().getDriverSeat().getY() < magicNumbers::endMoveOncomingCar)
	{
		SetChar(oncomingCar_->getCarBody().getDriverSeat().getX(),
			oncomingCar_->getCarBody().getDriverSeat().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getFrontRight().getX(),
			oncomingCar_->getCarWheels().getFrontRight().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getFrontLeft().getX(),
			oncomingCar_->getCarWheels().getFrontLeft().getY(), '+');
		
	}
	if (oncomingCar_->getCarBody().getPassengerSeat().getY() > magicNumbers::beginMoveOncomingCar &&
		oncomingCar_->getCarBody().getPassengerSeat().getY() < magicNumbers::endMoveOncomingCar)
	{
		SetChar(oncomingCar_->getCarBody().getPassengerSeat().getX(),
			oncomingCar_->getCarBody().getPassengerSeat().getY(), '+');
	}
	if (oncomingCar_->getCarBody().getRearPartOfCar().getY() > magicNumbers::beginMoveOncomingCar &&
		oncomingCar_->getCarBody().getRearPartOfCar().getY() < magicNumbers::endMoveOncomingCar)
	{
		SetChar(oncomingCar_->getCarBody().getRearPartOfCar().getX(),
			oncomingCar_->getCarBody().getRearPartOfCar().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getBackRight().getX(),
			oncomingCar_->getCarWheels().getBackRight().getY(), '+');
		SetChar(oncomingCar_->getCarWheels().getBackLeft().getX(),
			oncomingCar_->getCarWheels().getBackLeft().getY(), '+');
	}
}

void Scene::cleanRacing()
{
	SetChar(racing_.getCarBody().getFrontPartOfCar().getX(),
		racing_.getCarBody().getFrontPartOfCar().getY(), ' ');
	SetChar(racing_.getCarBody().getDriverSeat().getX(), 
		racing_.getCarBody().getDriverSeat().getY(), ' ');
	SetChar(racing_.getCarBody().getPassengerSeat().getX(), 
		racing_.getCarBody().getPassengerSeat().getY(), ' ');
	SetChar(racing_.getCarBody().getRearPartOfCar().getX(),
		racing_.getCarBody().getRearPartOfCar().getY(), ' ');
	SetChar(racing_.getCarWheels().getFrontRight().getX(),
		racing_.getCarWheels().getFrontRight().getY(), ' ');
	SetChar(racing_.getCarWheels().getFrontLeft().getX(), 
		racing_.getCarWheels().getFrontLeft().getY(), ' ');
	SetChar(racing_.getCarWheels().getBackRight().getX(), 
		racing_.getCarWheels().getBackRight().getY(), ' ');
	SetChar(racing_.getCarWheels().getBackLeft().getX(), 
		racing_.getCarWheels().getBackLeft().getY(), ' ');
}

void Scene::reset()
{
	cleanRacing();
	cleanOncoming();
	DiagonallyMove* temp = oncomingCar_;
	oncomingCar_ = nullptr;
	delete temp;
	int strip = rand() % magicNumbers::quantityStrips;
	DiagonallyMove* car = new DiagonallyMove(static_cast<magicNumbers::StripOfRoadway>(strip));
	oncomingCar_ = car;
	racing_.reset();
	collision_ = false;
	SetChar(magicNumbers::drawOfGGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfAGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfMGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfEGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfOGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfVGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfEEGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
	SetChar(magicNumbers::drawOfRGameOverByX, magicNumbers::drawOfGameOverByY, ' ');
}

const int Scene::getSpeed()
{
	return speedCounter_;
}

void Scene::cleanOncoming()
{
	if (oncomingCar_->getCarBody().getFrontPartOfCar().getY() > magicNumbers::startValueEnemyCar &&
		oncomingCar_->getCarBody().getFrontPartOfCar().getY() < magicNumbers::endValueEnemyCar)
	{
		SetChar(oncomingCar_->getCarBody().getFrontPartOfCar().getX(),
			oncomingCar_->getCarBody().getFrontPartOfCar().getY(), ' ');
	}
	if (oncomingCar_->getCarBody().getDriverSeat().getY() > magicNumbers::startValueEnemyCar &&
		oncomingCar_->getCarBody().getDriverSeat().getY() < magicNumbers::endValueEnemyCar)
	{
		SetChar(oncomingCar_->getCarWheels().getFrontRight().getX(),
			oncomingCar_->getCarWheels().getFrontRight().getY(), ' ');
		SetChar(oncomingCar_->getCarWheels().getFrontLeft().getX(),
			oncomingCar_->getCarWheels().getFrontLeft().getY(), ' ');
		SetChar(oncomingCar_->getCarBody().getDriverSeat().getX(), 
			oncomingCar_->getCarBody().getDriverSeat().getY(), ' ');
	}
	if (oncomingCar_->getCarBody().getPassengerSeat().getY() > magicNumbers::startValueEnemyCar &&
		oncomingCar_->getCarBody().getPassengerSeat().getY() < magicNumbers::endValueEnemyCar)
	{
		SetChar(oncomingCar_->getCarBody().getPassengerSeat().getX(),
			oncomingCar_->getCarBody().getPassengerSeat().getY(), ' ');
	}
	if (oncomingCar_->getCarBody().getRearPartOfCar().getY() > magicNumbers::startValueEnemyCar &&
		oncomingCar_->getCarBody().getRearPartOfCar().getY() < magicNumbers::endValueEnemyCar)
	{
		SetChar(oncomingCar_->getCarBody().getRearPartOfCar().getX(),
			oncomingCar_->getCarBody().getRearPartOfCar().getY(), ' ');
		SetChar(oncomingCar_->getCarWheels().getBackRight().getX(),
			oncomingCar_->getCarWheels().getBackRight().getY(), ' ');
		SetChar(oncomingCar_->getCarWheels().getBackLeft().getX(),
			oncomingCar_->getCarWheels().getBackLeft().getY(), ' ');
	}
}

void Scene::createFrame()
{
	for (int i = magicNumbers::beginOfFieldByCoordinateY;
		i < magicNumbers::endOfFieldByCoordinateY; i++)
	{
		for (int j = magicNumbers::beginOfFieldByCoordinateX;
			j < magicNumbers::endOfFieldByCoordinateX; j++) {
			if (i == magicNumbers::drawTopBorder ||
				j == magicNumbers::drawLeftBorder ||
				i == magicNumbers::drawBottomBorder ||
				j == magicNumbers::drawRightBorder)
			{
				SetChar(j, i, magicNumbers::symbolForDrawBorder);
			}
		}
	}
	
	SetChar(magicNumbers::drawLetterSByX, magicNumbers::drawWordSpeedByY, 'S');
	SetChar(magicNumbers::drawLetterPByX, magicNumbers::drawWordSpeedByY, 'p');
	SetChar(magicNumbers::drawLetterEByX, magicNumbers::drawWordSpeedByY, 'e');
	SetChar(magicNumbers::drawLetterEEByX, magicNumbers::drawWordSpeedByY, 'e');
	SetChar(magicNumbers::drawLetterDByX, magicNumbers::drawWordSpeedByY, 'd');
	SetChar(magicNumbers::drawLetterDoublePointByX, magicNumbers::drawWordSpeedByY, ':');
	SetChar(magicNumbers::drawOfSpeedByX, magicNumbers::drawOfSpeedByY, speed_);

	SetChar(racing_.getCarBody().getFrontPartOfCar().getX(),
		racing_.getCarBody().getFrontPartOfCar().getY(), '+');
	SetChar(racing_.getCarBody().getDriverSeat().getX(),
		racing_.getCarBody().getDriverSeat().getY(), '+');
	SetChar(racing_.getCarBody().getPassengerSeat().getX(),
		racing_.getCarBody().getPassengerSeat().getY(), '+');
	SetChar(racing_.getCarBody().getRearPartOfCar().getX(),
		racing_.getCarBody().getRearPartOfCar().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontRight().getX(),
		racing_.getCarWheels().getFrontRight().getY(), '+');
	SetChar(racing_.getCarWheels().getFrontLeft().getX(),
		racing_.getCarWheels().getFrontLeft().getY(), '+');
	SetChar(racing_.getCarWheels().getBackRight().getX(),
		racing_.getCarWheels().getBackRight().getY(), '+');
	SetChar(racing_.getCarWheels().getBackLeft().getX(),
		racing_.getCarWheels().getBackLeft().getY(), '+');
}

void Scene::checkCollisionCars()
{
	if (GetChar(oncomingCar_->getCarWheels().getFrontRight().getX() + 1,
		(oncomingCar_->getCarWheels().getFrontRight().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarWheels().getFrontLeft().getX() + 1,
		(oncomingCar_->getCarWheels().getFrontLeft().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarBody().getRearPartOfCar().getX() + 1,
		(oncomingCar_->getCarBody().getRearPartOfCar().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarWheels().getBackRight().getX() + 1,
		(oncomingCar_->getCarWheels().getBackRight().getY() + 1)) == '+' ||
		GetChar(oncomingCar_->getCarWheels().getBackLeft().getX() + 1,
		(oncomingCar_->getCarWheels().getBackLeft().getY() + 1)) == '+')
	{
		collision_ = true;
	}
}
