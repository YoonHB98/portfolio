#pragma once
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>

// Ό³Έν :
enum class SoundState
{
	Coin,
	Point

};
class Sound : public GameEngineActor
{
public:
	// constrcuter destructer
	Sound();
	~Sound();

	// delete Function
	Sound(const Sound& _Other) = delete;
	Sound(Sound&& _Other) noexcept = delete;
	Sound& operator=(const Sound& _Other) = delete;
	Sound& operator=(Sound&& _Other) noexcept = delete;
	static std::string SoundPlay;
protected:

private:
	float Time;
	GameEngineRenderer* One;
	void Start() override;
	void Update() override;
	GameEngineSoundPlayer BgmPlayer;
};

