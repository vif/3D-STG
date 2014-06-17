#include "basic_attack.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <utilities/MathConversions/math_conversions.hpp>

BasicAttack::BasicAttack(double damage, double expiration_time_delta, glm::vec3 init_position, glm::quat init_rotation, glm::vec3 direction) :
Model("Resources/models/projectile/basic_attack.dae", &Global::shader_manager->phong3d),
ScriptableObject(ScriptableObject::ObjectType::SIMULATED, init_position, init_rotation, static_cast<Model*>(this), 10)
{
	this->damage = damage;
	_direction = direction;
	_expiration_time_delta = expiration_time_delta;

	rigid_body->setUserPointer(static_cast<ICollidable*>(this));
	rigid_body->setCollisionFlags(rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

void BasicAttack::Update(double dt)
{
	if (_expiration_time_delta < 0)
	{
		active = false;
	}
	else
	{
		_expiration_time_delta -= dt;

		rigid_body->activate(true);

		rigid_body->setLinearVelocity(toVec3(_direction));
	}
}
