#pragma once

#include <object_types/enemy.hpp>
#include <ship/ship.hpp>

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(Ship* ship, Model::Model* model, glm::vec3 init_pos, glm::quat init_orientation) :
		_ship(ship),
		Enemy(ScriptableObject::ObjectType::SIMULATED, init_pos, init_orientation, model, 10) 
	{}
	void Update(double dt) override;
private:
	Ship* _ship;
};