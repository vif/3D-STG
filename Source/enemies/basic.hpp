#pragma once

#include <object_types/enemy.hpp>

class Ship;

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(Ship* ship) : _ship(ship){}
	const float movementspeed = 10;
	void Update(double dt) override;
private:
	Ship* _ship;
};