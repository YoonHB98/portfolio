#pragma once

// Ό³Έν :
class FlyingTurtle
{
public:
	// constrcuter destructer
	FlyingTurtle();
	~FlyingTurtle();

	// delete Function
	FlyingTurtle(const FlyingTurtle& _Other) = delete;
	FlyingTurtle(FlyingTurtle&& _Other) noexcept = delete;
	FlyingTurtle& operator=(const FlyingTurtle& _Other) = delete;
	FlyingTurtle& operator=(FlyingTurtle&& _Other) noexcept = delete;

protected:

private:

};

