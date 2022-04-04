#pragma once
#include <GameEngine/GameEngineActor.h>


enum PlayerState
{
	Idle,
	Attck,
	Move,
	Max,
};

class GameEngineImage;
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* RenderRun;
	int Right;
	int Left;
	float Speed_;
	float Gravity_;
	float AccGravity_;
	GameEngineImage* WhiteMap_;
	GameEngineCollision* PlayerCollision;
	void Start() override;
	void Update() override;
	void Render() override;
};

