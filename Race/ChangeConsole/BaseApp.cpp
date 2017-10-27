#include "../stdafx.h"
#include <algorithm>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <cassert>
#include <strsafe.h>
#include "../Scene.h"

#define MY_PERFORMENCE_COUNTER

#include "PerformanceCounter.h"

BaseApp::BaseApp(int xSize, int ySize) : X_SIZE(xSize), Y_SIZE(ySize)
{
	SMALL_RECT windowSize = {0, 0, X_SIZE, Y_SIZE};
	COORD windowBufSize = {X_SIZE+1, Y_SIZE+1};

	mConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
	mConsoleIn_ = GetStdHandle(STD_INPUT_HANDLE);

	if(!SetConsoleScreenBufferSize(mConsole_,  windowBufSize))
	{
		cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << endl;
	}
	if(!SetConsoleWindowInfo(mConsole_, TRUE, &windowSize))
	{
		cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
	}

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole_, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsole_, &cursorInfo);


	mChiBuffer_ = (CHAR_INFO*)malloc((X_SIZE+1)*(Y_SIZE+1)*sizeof(CHAR_INFO));

	mDwBufferSize_.X = X_SIZE + 1;
	mDwBufferSize_.Y = Y_SIZE + 1;		// размер буфера данных

	mDwBufferCoord_.X = 0;
	mDwBufferCoord_.Y = 0;				// координаты €чейки

	mLpWriteRegion_.Left = 0;
	mLpWriteRegion_.Top = 0;
	mLpWriteRegion_.Right = X_SIZE + 1;
	mLpWriteRegion_.Bottom = Y_SIZE + 1;	// пр€моугольник дл€ чтени€


	for (int x=0; x<X_SIZE+1; x++) {
		for (int y=0; y<Y_SIZE+1; y++) {
			SetChar(x, y, L' ');
		}
	}
}

BaseApp::~BaseApp()
{
	free(mChiBuffer_);
}

void BaseApp::SetChar(int x, int y, wchar_t c)
{
	mChiBuffer_[x + (X_SIZE+1)*y].Char.UnicodeChar = c;
	
	mChiBuffer_[x + (X_SIZE+1)*y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;

}

void BaseApp::SetChar(int x, int y, int c)
{
	mChiBuffer_[x + (X_SIZE+1)*y].Char.UnicodeChar = c;
	
	mChiBuffer_[x + (X_SIZE+1)*y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;

}


wchar_t BaseApp::GetChar(int x, int y)
{
	return mChiBuffer_[x + (X_SIZE+1)*y].Char.AsciiChar;
}

void BaseApp::Render()
{
	if (!WriteConsoleOutput(mConsole_, mChiBuffer_, mDwBufferSize_, mDwBufferCoord_, &mLpWriteRegion_)) {
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError()); 
	}
}

void BaseApp::Run()
{
	CStopwatch timer;
	int sum = 0;
	int counter = 0;

	int deltaTime = 0;
	while (true) {
		timer.Start();
		if (kbhit()) {

			KeyPressed (getch());
			if (!FlushConsoleInputBuffer(mConsoleIn_)) {
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
			}
		}

		UpdateF((float)deltaTime / 1000.0f);
		Render();
		Sleep(1);

		while (true) {
			deltaTime = timer.Now();
			if (kbhit()) {

				KeyPressed(getch());
				if (!FlushConsoleInputBuffer(mConsoleIn_))
					cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
			}
			if (deltaTime > Scene::getSpeed()) {
				break;
			}
		}

		sum += deltaTime;
		counter++;
		if (sum >= 1000) {
			TCHAR  szbuff[255];
			StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
			SetConsoleTitle(szbuff);

			counter = 0;
			sum = 0;
		}
	}
}
