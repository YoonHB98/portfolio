#pragma once
#include <GameEngine/GameEngineLevel.h>
#include "TopUI.h"
#include "Player.h"
#include "Map1Under.h"
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

// Ό³Έν :

class Stage2 : public GameEngineLevel
{
public:
	// constrcuter destructer
	Stage2();
	~Stage2();

	// delete Function
	Stage2(const Stage2& _Other) = delete;
	Stage2(Stage2&& _Other) noexcept = delete;
	Stage2& operator=(const Stage2& _Other) = delete;
	Stage2& operator=(Stage2&& _Other) noexcept = delete;
	GameEngineSoundPlayer BgmPlayer;
protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	static bool PipeOn;
private:
	bool pausefirst_ = false;
	bool bgm = false;
	BigPlayer* BigMario;
	Player* Mario;
	float Time;
	TopUI* UI;
	Coin* UICOIN;


};

