#pragma once
#include <string>
#include "GameEngineBase/GameEngineMath.h"
// ???? :
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
	static bool flowerfirst;
	static bool flower;
	static bool star;
	static bool end;
	static bool first;
	static bool endtime;
	static bool pipedown;
	static bool pipeleft;
	static bool flag;
	static bool gameend;
	static bool CreateKeyFirst;
	static bool KoopaDeath;
	static bool Stage2Sound;
	static bool GameRealEnd;
	static std::string PlayerStatus;
	static float4 PlayerPosition;
protected:

private:

};

