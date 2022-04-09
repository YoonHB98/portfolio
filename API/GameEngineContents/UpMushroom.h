#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class UpMushroom : public GameEngineActor
{
public:
	// constrcuter destructer
	UpMushroom();
	~UpMushroom();

	// delete Function
	UpMushroom(const UpMushroom& _Other) = delete;
	UpMushroom(UpMushroom&& _Other) noexcept = delete;
	UpMushroom& operator=(const UpMushroom& _Other) = delete;
	UpMushroom& operator=(UpMushroom&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Update() override;
};

