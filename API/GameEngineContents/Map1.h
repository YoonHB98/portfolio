#pragma once
#include "GameEngine/GameEngineActor.h"


// Ό³Έν :
class Map1 : public GameEngineActor
{
public:
	// constrcuter destructer
	Map1();
	~Map1();

	// delete Function
	Map1(const Map1& _Other) = delete;
	Map1(Map1&& _Other) noexcept = delete;
	Map1& operator=(const Map1& _Other) = delete;
	Map1& operator=(Map1&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;

private:

};

