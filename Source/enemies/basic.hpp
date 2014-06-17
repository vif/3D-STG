#pragma once

#include <object_types/scriptable_object.hpp>
#include <object_types/icollidable.hpp>
#include <object_types/killable.hpp>
#include <ship/ship.hpp>

class BasicEnemy : public ScriptableObject, public ICollidable, public Killable
{
public:
	BasicEnemy(Ship* ship, Model::Model* model, glm::vec3 init_pos, glm::quat init_orientation) :
		_ship(ship),
		ScriptableObject(ScriptableObject::ObjectType::SIMULATED, init_pos, init_orientation, model, 10),
		Killable(100.0)
	{}
	void Update(double dt) override;
	void Collision(ICollidable*) override;
private:
	Ship* _ship;
};