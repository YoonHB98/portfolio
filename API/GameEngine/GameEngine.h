#pragma once
#include <map>
#include <string>
#include<GameEngineBase/GameEngineDebug.h>

// 설명 : 게임엔진 게임 시작점과 끝점 실행중 담당 인터페이스 제공
class GameEngineLevel;
class GameEngine
{
public:
	// constrcuter destructer
	GameEngine();
	~GameEngine();

	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

	virtual void GameInit() = 0;
	virtual void GameLoop() = 0;
	virtual void GameEnd() = 0;

	//엔진 시작
	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();


		GameType UserGame;
		UserContents_ = &UserGame;

		WindowCreate();

	}

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new  LevelType();
		NewLevel->SetName(_Name);
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}
private:
	static std::map<std::string, GameEngineLevel*> AllLevel_;
	static GameEngine* UserContents_;
	
	static void WindowCreate();

	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};

