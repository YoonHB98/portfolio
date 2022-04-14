#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineActor.h>


// Ό³Έν :


class flag : public GameEngineActor
{
public:
	// constrcuter destructer
	flag();
	~flag();

	// delete Function
	flag(const flag& _Other) = delete;
	flag(flag&& _Other) noexcept = delete;
	flag& operator=(const flag& _Other) = delete;
	flag& operator=(flag&& _Other) noexcept = delete;
	GameEngineCollision* EndCollision;
	void Createflag(const float4& _Pivot);
protected:

private:
	float Time_ = 0;
	void Start() override;
	void Update() override;
	bool first = true;

};

