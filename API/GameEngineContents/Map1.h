#pragma once
#include <GameEngine/GameEngineActor.h>


class GameEngineRenderer;
class Map1 : public GameEngineActor
{
	static Map1* CuBackGround;
public:
	// constrcuter destructer
	Map1();
	~Map1();

	// delete Function
	Map1(const Map1& _Other) = delete;
	Map1(Map1&& _Other) noexcept = delete;
	Map1& operator=(const Map1& _Other) = delete;
	Map1& operator=(Map1&& _Other) noexcept = delete;

	GameEngineRenderer* GetRenderer()
	{
		return Image_;
	}

protected:
	void Start() override;
	void Update() override;

private:
	GameEngineRenderer* Image_;
};

