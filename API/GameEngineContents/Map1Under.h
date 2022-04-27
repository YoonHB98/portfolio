#pragma once
#include <GameEngine/GameEngineActor.h>


class GameEngineRenderer;
class Map1Under : public GameEngineActor
{
	//static Map1Under* CuBackGround;
public:
	// constrcuter destructer
	Map1Under();
	~Map1Under();

	// delete Function
	Map1Under(const Map1Under& _Other) = delete;
	Map1Under(Map1Under&& _Other) noexcept = delete;
	Map1Under& operator=(const Map1Under& _Other) = delete;
	Map1Under& operator=(Map1Under&& _Other) noexcept = delete;
	GameEngineRenderer* GetRenderer()
	{
		return Image_;
	}

protected:
	void Start() override;
	void Render() override;

private:
	GameEngineRenderer* Image_;
};

