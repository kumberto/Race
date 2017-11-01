// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#ifndef BASEAPP_H
#define BASEAPP_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "../MagicNumbers.h"

using namespace std;

class BaseApp
{
	public:
		//������� ������� ������ �� ����������� � ��������� � ��������
		const int X_SIZE;
		const int Y_SIZE;

		//����������� �������� ������� ������� ������ �� ����������� � ��������� � ��������
		BaseApp(int xSize = magicNumbers::defaultX, int ySize = magicNumbers::defaultY);
		virtual ~BaseApp();
		BaseApp(const BaseApp& baseApp) = delete;
		BaseApp& operator=(const BaseApp& baseApp) = delete;
		BaseApp(BaseApp&& baseApp) = delete;
		BaseApp& operator=(BaseApp&& baseApp) = delete;
		//��������� ������� ����
		void Run();

		//����� ��������� x,y-������ ������ ������������ ��������, ��� ������� ���
		inline void SetChar(int x, int y, wchar_t c);
		void SetChar(int x, int y, int c);
		wchar_t GetChar(int x, int y);

		/*��� ������� ���������� ������ ������� ��������, � ����� ��������������, � ���������� ������.
		� �� �������� deltaTime - ������� �� ������� ����� ���������� ��������� � ����, � ��������*/
		virtual void updateGameField(float deltaTime){}
		/*��� ������� ���������� ��� ������� ������� �� ����������, � �� �������� ��� ������� - btnCode.
		���� ������������ ������� ��� �������������� �������, �� ������ ����� ��� ��� �����, �������� 224, � ��������� �� ��� - 
		����� ��� ��������������� ��� ����� �������, ��� ����� ��������, ������ ����� getch().
		����� KeyPressed ��� �� ����� �������������� � ����������*/
		virtual void keyPressed (const int btnCode){}
	private:
		HANDLE mConsole_;
		HANDLE mConsoleIn_;

		CHAR_INFO* mChiBuffer_;
		COORD mDwBufferSize_;
		COORD mDwBufferCoord_;
		SMALL_RECT mLpWriteRegion_;

		void render();

};
#endif