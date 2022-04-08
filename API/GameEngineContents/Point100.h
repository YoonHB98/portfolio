#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class Point100 : public GameEngineActor
{
public:
	// constrcuter destructer
	Point100();
	~Point100();

	// delete Function
	Point100(const Point100& _Other) = delete;
	Point100(Point100&& _Other) noexcept = delete;
	Point100& operator=(const Point100& _Other) = delete;
	Point100& operator=(Point100&& _Other) noexcept = delete;

	float Time;
protected:

private:
	void Start() override;
	void Update() override;
};

