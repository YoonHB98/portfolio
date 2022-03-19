#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class Point : public GameEngineActor
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

protected:

private:
	void Start() override;
	void Render() override;
};

