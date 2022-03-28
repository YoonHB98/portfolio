#pragma once

// Ό³Έν :
class UnderStage
{
public:
	// constrcuter destructer
	UnderStage();
	~UnderStage();

	// delete Function
	UnderStage(const UnderStage& _Other) = delete;
	UnderStage(UnderStage&& _Other) noexcept = delete;
	UnderStage& operator=(const UnderStage& _Other) = delete;
	UnderStage& operator=(UnderStage&& _Other) noexcept = delete;

protected:

private:

};

