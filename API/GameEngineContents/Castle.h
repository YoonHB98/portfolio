#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>


// Ό³Έν :


class Castle : public GameEngineActor
{
public:
	// constrcuter destructer
	Castle();
	~Castle();

	// delete Function
	Castle(const Castle& _Other) = delete;
	Castle(Castle&& _Other) noexcept = delete;
	Castle& operator=(const Castle& _Other) = delete;
	Castle& operator=(Castle&& _Other) noexcept = delete;
	GameEngineCollision* EndCollision;
	void CreateCastle(const float4& _Pivot);
protected:

private:
	bool flagfirst = true;
	float Time_ = 0;
	void Start() override;
	void Update() override;
	void Render() override;

};

