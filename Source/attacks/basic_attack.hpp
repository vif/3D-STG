#pragma once

#include <object_types/scriptable_object.hpp>
#include <object_types/icollidable.hpp>
#include <glm/common.hpp>

class BasicAttack : private Model::Model, public ScriptableObject, public ICollidable
{
public:
	BasicAttack(double damage, double expiration_time_delta, glm::vec3 init_position, glm::quat init_rotation, glm::vec3 direction);
	void Update(double dt) override;
	void Collision(ICollidable*) override {}
	bool active = true;
	double damage;
private:
	double _expiration_time_delta;
	glm::vec3 _direction;
};