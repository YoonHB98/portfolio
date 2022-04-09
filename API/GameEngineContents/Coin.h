#pragma once

#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class Coin : public GameEngineActor
{
public:
	// constrcuter destructer
	Coin();
	~Coin();

	// delete Function
	Coin(const Coin& _Other) = delete;
	Coin(Coin&& _Other) noexcept = delete;
	Coin& operator=(const Coin& _Other) = delete;
	Coin& operator=(Coin&& _Other) noexcept = delete;
	static int CoinUI;
	inline void Point(const int& _Other)
	{
		CoinUI = CoinUI + _Other;
	}


protected:

private:
	GameEngineRenderer* Actor;
	GameEngineRenderer* Two;
	GameEngineRenderer* One;
	void Start() override;
	void Update() override;
	void Render() override;
};

