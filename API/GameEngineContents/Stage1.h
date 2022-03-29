#pragma once
#include <GameEngine/GameEngineLevel.h>

// Ό³Έν :
class Stage1 : public GameEngineLevel
{
public:
	// constrcuter destructer
	Stage1();
	~Stage1();

	// delete Function
	Stage1(const Stage1& _Other) = delete;
	Stage1(Stage1&& _Other) noexcept = delete;
	Stage1& operator=(const Stage1& _Other) = delete;
	Stage1& operator=(Stage1&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;

private:


};

