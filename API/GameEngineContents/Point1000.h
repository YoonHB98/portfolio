#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class Point1000 : public GameEngineActor
{
public:
	// constrcuter destructer
	Point1000();
	~Point1000();

	// delete Function
	Point1000(const Point1000& _Other) = delete;
	Point1000(Point1000&& _Other) noexcept = delete;
	Point1000& operator=(const Point1000& _Other) = delete;
	Point1000& operator=(Point1000&& _Other) noexcept = delete;

	float Time;
protected:

private:
	void Start() override;
	void Update() override;
};

