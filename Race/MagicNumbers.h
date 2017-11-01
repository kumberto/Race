#ifndef MAGICNUMBERS_H
#define MAGICNUMBERS_H
namespace magicNumbers {
	enum StripOfRoadway { LEFT_STRIP = 0, CENTRAL_STRIP, RIGHT_STRIP };
	enum DirectionMovement { UP = 0, DOWN, LEFT, RIGHT, DIAGONALLYTOUP, DIAGONALLYTODOWN };
	enum Cars{RACING_CAR = 0, ONCOMING_CAR};
	static int widthApp = 50;
	static int heightApp = 30;

	//speed
	static const int startingSpeed = 49;
	static const int lowerSpeedLimit = 48;
	static const int upperSpeedLimit = 58;
	static const int lowerCounterLimitSpeed = 300;
	static const int upperCounterLimitSpeed = 60;
	static const int stepCounter = 30;
	static const int stepSpeed = 1;

	//Key
	static const int downKey = 80;
	static const int leftKey = 75;
	static const int rightKey = 77;
	static const int upKey = 72;
	static const int enterKey = 13;
	static const int exitKey = 27;
	static const int resetKey = 83;
	static const int speedUpKey = 73;
	static const int speedDownKey = 81;

	//moveCar
	static const int unitOfMovement = 1;
	static const int beginMoveOncomingCar = 4;
	static const int endMoveOncomingCar = 30;
	static const int quantityStrips = 3;
	static const int leftMove = -1;
	static const int rightMove = 1;
	static const int upMove = -1;
	static const int downMove = 1;

	//BaseApp
	static const float millisecondsPerSecond = 1000.0;
	static const int defaultX = 100;
	static const int defaultY = 80;
	static const int expandingReadingField = 1;

	//pause
	static const int drawOfPauseByY = 12;
	static const int drawOfPByX = 23;
	static const int drawOfAByX = 24;
	static const int drawOfUByX = 25;
	static const int drawOfSByX = 26;
	static const int drawOfEByX = 27;

	//gameover
	static const int drawOfGameOverByY = 12;
	static const int drawOfGGameOverByX = 21;
	static const int drawOfAGameOverByX = 22;
	static const int drawOfMGameOverByX = 23;
	static const int drawOfEGameOverByX = 24;
	static const int drawOfOGameOverByX = 26;
	static const int drawOfVGameOverByX = 27;
	static const int drawOfEEGameOverByX = 28;
	static const int drawOfRGameOverByX = 29;

	//field
	static const int borderLeftSide = 16;
	static const int borderRightSide = 34;
	static const int borderTopSide = 5;
	static const int borderBottonSide = 29;
	static const int beginOfFieldByCoordinateY = 4;
	static const int endOfFieldByCoordinateY = 31;
	static const int beginOfFieldByCoordinateX = 15;
	static const int endOfFieldByCoordinateX = 36;
	static const int drawTopBorder = 4;
	static const int drawBottomBorder = 30;
	static const int drawLeftBorder = 15;
	static const int drawRightBorder = 35;
	static const char symbolForDrawBorder = '#';

	//word SPEED:
	static const int drawWordSpeedByY = 3;
	static const int drawLetterSByX = 36;
	static const int drawLetterPByX = 37;
	static const int drawLetterEByX = 38;
	static const int drawLetterEEByX = 39;
	static const int drawLetterDByX = 40;
	static const int drawLetterDoublePointByX = 41;
	static const int drawOfSpeedByX = 42;
	static const int drawOfSpeedByY = 3;

	//RacingCar
	static const int valueXForConstructionBody = 25;
	static const int valueYForFrontPartBody = 16;
	static const int valueYForDriverSeatBody = 17;
	static const int valueYForPassengerBody = 18;
	static const int valueYForRearPartBody = 19;
	static const int valueXLeftWheels = 24;
	static const int valueYFrontWheels = 17;
	static const int valueXRightWheels = 26;
	static const int valueYBackWheels = 19;

	//OncomingCar
	static const int valueXBodyLeftStrip = 22;
	static const int valueXLeftWheelsLeftStrip = 21;
	static const int valueXRightWheelsLeftStrip = 23;
	static const int valueXBodyCentralStrip = 25;
	static const int valueXLeftWheelsCentralStrip = 24;
	static const int valueXRightWheelsCentralStrip = 26;
	static const int valueXBodyRightStrip = 28;
	static const int valueXLeftWheelsRightStrip = 27;
	static const int valueXRightWheelsRightStrip = 29;
	static const int valueYFrontPartBody = 3;
	static const int valueYDriverSeatBody = 2;
	static const int valueYPassengerSeatBody = 1;
	static const int valueYRearPartBody = 0;
	static const int valueYFrontWheelsAllStrip = 2;
	static const int valueYBackWheelsAllStrip = 0;

	//cleanCar
	static const int startValueEnemyCar = 4;
	static const int endValueEnemyCar = 30;

}
#endif