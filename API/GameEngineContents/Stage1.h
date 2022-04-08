#pragma once
#include <GameEngine/GameEngineLevel.h>
#include "TopUI.h"
#include "Player.h"
#include "Map1.h"
#include "Block.h"
#include "QuestionBlock.h"
#include "Goomba.h"
#include "Coin.h"
#include "BoxCoin.h"
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include<GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineSound.h>

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
	GameEngineSoundPlayer BgmPlayer;
protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;

private:
	TopUI* UI;


};

