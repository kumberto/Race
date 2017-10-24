#pragma once
class Point
{
	public:
		Point(int x = 0, int y = 0);
		int getX() const;
		void setX(int x);
		int getY() const;
		void setY(int y);
	private:
		int x_;
		int y_;
};

