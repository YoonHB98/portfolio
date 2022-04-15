#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class LevelIntro : public GameEngineActor
{
public:
	// constrcuter destructer
	LevelIntro();
	~LevelIntro();

	// delete Function
	LevelIntro(const LevelIntro& _Other) = delete;
	LevelIntro(LevelIntro&& _Other) noexcept = delete;
	LevelIntro& operator=(const LevelIntro& _Other) = delete;
	LevelIntro& operator=(LevelIntro&& _Other) noexcept = delete;
	static int DeathCount;
protected:
	float Time_;
	void Start() override;
	void Update() override;
	void Render() override;
private:
	GameEngineRenderer* Count;
	GameEngineRenderer* StageCount;
};

