#pragma once

#include <object_types/enemy.hpp>

class BasicEnemy : public Enemy
{
public:
	const float movementspeed = 10;
	void Update(double dt, World* world) override;
private:
};