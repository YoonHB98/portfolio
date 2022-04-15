#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
// Ό³Έν :
class WorldCount : public GameEngineActor
{
public:
	// constrcuter destructer
	WorldCount();
	~WorldCount();

	// delete Function
	WorldCount(const WorldCount& _Other) = delete;
	WorldCount(WorldCount&& _Other) noexcept = delete;
	WorldCount& operator=(const WorldCount& _Other) = delete;
	WorldCount& operator=(WorldCount&& _Other) noexcept = delete;
	static int WorldCountUI ;
	
protected:

private:
	GameEngineRenderer* One;
	GameEngineRenderer* Two;
	void Start() override;
	void Update() override;
};

