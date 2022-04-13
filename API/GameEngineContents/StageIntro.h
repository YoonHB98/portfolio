#pragma once
#include "TitleLevel.h"
#include <GameEngine/GameEngine.h>
#include "TitleBackGround.h"
#include "TitleCharacter.h"
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineLevel.h>
#include "Coin.h"

// Ό³Έν :
class StageIntro : public GameEngineLevel 
{
public:
	// constrcuter destructer
	StageIntro();
	~StageIntro();

	// delete Function
	StageIntro(const StageIntro& _Other) = delete;
	StageIntro(StageIntro&& _Other) noexcept = delete;
	StageIntro& operator=(const StageIntro& _Other) = delete;
	StageIntro& operator=(StageIntro&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update();

private:

};

