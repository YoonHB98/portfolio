#pragma once
#include <string>
#include "GameEngineBase/GameEngineMath.h"
// Ό³Έν :
class Pause
{
public:
	// constrcuter destructer
	Pause();
	~Pause();

	// delete Function
	Pause(const Pause& _Other) = delete;
	Pause(Pause&& _Other) noexcept = delete;
	Pause& operator=(const Pause& _Other) = delete;
	Pause& operator=(Pause&& _Other) noexcept = delete;
	static bool pause;
	static bool death;
	static bool bigfirst;
	static bool smallfirst;
	static bool flower;
	static bool end;
	static bool first;
	static std::string PlayerStatus;
	static float4 PlayerPosition;
protected:

private:

};

