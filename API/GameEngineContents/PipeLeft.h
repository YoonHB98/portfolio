#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineCollision.h>


// Ό³Έν :
class PipeLeft : public GameEngineActor
{
public:
	// constrcuter destructer
	PipeLeft();
	~PipeLeft();

	// delete Function
	PipeLeft(const PipeLeft& _Other) = delete;
	PipeLeft(PipeLeft&& _Other) noexcept = delete;
	PipeLeft& operator=(const PipeLeft& _Other) = delete;
	PipeLeft& operator=(PipeLeft&& _Other) noexcept = delete;
	GameEngineCollision* PipeLeftCollision;
	float Time;
protected:

private:
	void Start() override;
	void Update() override;
};

