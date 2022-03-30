#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class PlayerAnimation : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerAnimation();
	~PlayerAnimation();

	// delete Function
	PlayerAnimation(const PlayerAnimation& _Other) = delete;
	PlayerAnimation(PlayerAnimation&& _Other) noexcept = delete;
	PlayerAnimation& operator=(const PlayerAnimation& _Other) = delete;
	PlayerAnimation& operator=(PlayerAnimation&& _Other) noexcept = delete;
	void RunRight();
protected:

private:
	float Speed_;


};

