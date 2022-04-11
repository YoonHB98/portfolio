#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class Point200 : public GameEngineActor
{
public:
	// constrcuter destructer
	Point200();
	~Point200();

	// delete Function
	Point200(const Point200& _Other) = delete;
	Point200(Point200&& _Other) noexcept = delete;
	Point200& operator=(const Point200& _Other) = delete;
	Point200& operator=(Point200&& _Other) noexcept = delete;

	float Time;
protected:

private:
	void Start() override;
	void Update() override;
};

