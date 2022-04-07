#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class QuestionBlock : public GameEngineActor
{
public:
	// constrcuter destructer
	QuestionBlock();
	~QuestionBlock();

	// delete Function
	QuestionBlock(const QuestionBlock& _Other) = delete;
	QuestionBlock(QuestionBlock&& _Other) noexcept = delete;
	QuestionBlock& operator=(const QuestionBlock& _Other) = delete;
	QuestionBlock& operator=(QuestionBlock&& _Other) noexcept = delete;
	GameEngineCollision* BlockCollision;
	void CreateQuestionBlock(const float4& _Pivot);
protected:

private:
	int up = 0;
	int down = 0;
	float Time_ = 0;
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
};

