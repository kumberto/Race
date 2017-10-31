// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#ifndef BASEAPP_H
#define BASEAPP_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

class BaseApp
{
	private:
		HANDLE mConsole_;
		HANDLE mConsoleIn_;

		CHAR_INFO* mChiBuffer_;
		COORD mDwBufferSize_;
		COORD mDwBufferCoord_;
		SMALL_RECT mLpWriteRegion_;

		void render();

	public:
		//размеры области вывода по горизонтали и вертикали в символах
		const int X_SIZE;
		const int Y_SIZE;

		//аргументами €вл€ютс€ размеры области вывода по горизонтали и вертикали в символах
		BaseApp(int xSize=100, int ySize=80);
		virtual ~BaseApp();
		BaseApp(const BaseApp& baseApp) = delete;
		BaseApp& operator=(const BaseApp& baseApp) = delete;
		BaseApp(BaseApp&& baseApp) = delete;
		BaseApp& operator=(BaseApp&& baseApp) = delete;
		//запускает игровой цикл
		void Run();

		//можно заполнить x,y-символ экрана определенным символом, или считать его
		inline void SetChar(int x, int y, wchar_t c);
		void SetChar(int x, int y, int c);
		wchar_t GetChar(int x, int y);

		/*эта функци€ вызываетс€ каждую игровую итерацию, еЄ можно переопределить, в наследнике класса.
		в неЄ приходит deltaTime - разница во времени между предыдущей итерацией и этой, в секундах*/
		virtual void updateGameField(float deltaTime){}
		/*эта функци€ вызываетс€ при нажатии клавиши на клавиатуре, в неЄ приходит код клавиши - btnCode.
		если использовать стрелки или функциональные клавиши, то придет общее дл€ них число, например 224, а следующее за ним - 
		будет уже непосредственно код самой клавиши, его можно получить, вызвав метод getch().
		ћетод KeyPressed так же можно переопределить в наследнике*/
		virtual void keyPressed (const int btnCode){}
};
#endif