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
#include "Point.h"
#include "BigPlayer.h"

// 설명 :

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
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

private:
	bool bgm = false;
	BigPlayer* BigMario;
	Player* Mario;
	float Time;
	TopUI* UI;
	Coin* UICOIN;
	//몬스터
	Goomba* Goomba1;
	Goomba* Goomba2;
	Goomba* Goomba3;
	Goomba* Goomba4;
	Goomba* Goomba5;
	Goomba* Goomba6;
	Goomba* Goomba7;
	Goomba* Goomba8;
	Goomba* Goomba9;
	Goomba* Goomba10;
	Goomba* Goomba11;
	Goomba* Goomba12;
	Goomba* Goomba13;
	Goomba* Goomba14;
	Goomba* Goomba15;
	Goomba* Goomba16;

};

