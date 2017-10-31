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
		//������� ������� ������ �� ����������� � ��������� � ��������
		const int X_SIZE;
		const int Y_SIZE;

		//����������� �������� ������� ������� ������ �� ����������� � ��������� � ��������
		BaseApp(int xSize=100, int ySize=80);
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
};
#endif