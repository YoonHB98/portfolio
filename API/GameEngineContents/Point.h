#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
// Ό³Έν :
class Point : public GameEngineActor
{
public:
	// constrcuter destructer
	Point();
	~Point();

	// delete Function
	Point(const Point& _Other) = delete;
	Point(Point&& _Other) noexcept = delete;
	Point& operator=(const Point& _Other) = delete;
	Point& operator=(Point&& _Other) noexcept = delete;
	static int PointUI ;
	inline void Pointer(const int& _Other)
	{
			PointUI = PointUI + _Other;
	}
	
protected:

private:
	GameEngineRenderer* One;
	GameEngineRenderer* Two;
	GameEngineRenderer* Three;
	GameEngineRenderer* Four;
	GameEngineRenderer* Five;
	void Start() override;
	void Update() override;
};

