#pragma once

// Ό³Έν :
class Point
{
public:
	// constrcuter destructer
	Point();
	~Point();

	// delete Function
	Point(const Point& _Other) = delete;
	Point(Point&& _Other) noexcept = delete;
	Point& operator=(const Point& _Other) = delete;
	Point& operator=(Point&& _Other) noexcept = delete;
	static int PointUI;
protected:

private:

};

