#pragma once

// Ό³Έν :
class World
{
public:
	// constrcuter destructer
	World();
	~World();

	// delete Function
	World(const World& _Other) = delete;
	World(World&& _Other) noexcept = delete;
	World& operator=(const World& _Other) = delete;
	World& operator=(World&& _Other) noexcept = delete;

protected:

private:

};

