#pragma once
class Point
{
	public:
		Point(int x = 0, int y = 0);
		Point(const Point& point) = delete;
		Point& operator=(const Point& point) = delete;
		Point(Point&& point) = delete;
		Point& operator=(Point&& point) = delete;
		int getX() const;
		void setX(int x);
		int getY() const;
		void setY(int y);
	private:
		int x_;
		int y_;
};

