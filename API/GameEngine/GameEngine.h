#pragma once
#include <map>
#include <string>

// ���� : ���ӿ��� ���� �������� ���� ������ ��� �������̽� ����
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

	virtual void GameInit();
	virtual void GameLoop();
	virtual void GameEnd();

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new  LevelType();
		NewLevel->SetName(_Name);
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}
private:
	std::map<std::string, GameEngineLevel*> AllLevel_;
};

