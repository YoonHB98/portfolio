#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineActor.h>


// Ό³Έν :


class CastleFlag : public GameEngineActor
{
public:
	// constrcuter destructer
	CastleFlag();
	~CastleFlag();

	// delete Function
	CastleFlag(const CastleFlag& _Other) = delete;
	CastleFlag(CastleFlag&& _Other) noexcept = delete;
	CastleFlag& operator=(const CastleFlag& _Other) = delete;
	CastleFlag& operator=(CastleFlag&& _Other) noexcept = delete;
	void CreateCastleFlag(const float4& _Pivot);
protected:

private:
	float Time_ = 0;
	void Start() override;
	void Update() override;
	bool first = true;

};

