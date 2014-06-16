#include "ship.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <world/world.hpp>

Ship::Ship() :
Model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d),
ScriptableObject(ScriptableObject::ObjectType::SIMULATED, glm::vec3(10, 0, 0), glm::quat(), static_cast<Model*>(this), 100)
{
	rigid_body->setUserPointer(static_cast<ICollidable*>(this));
	rigid_body->setCollisionFlags(rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

void Ship::Update(double dt)
{
	rigid_body->activate(true);

	auto transform = rigid_body->getWorldTransform();
	auto rotation = transform.getRotation();

	const float max_speed = 100;

	if (input.propel_forward)
	{
		rigid_body->applyCentralImpulse(quatRotate(rotation, btVector3(max_speed, 0, 0) * dt));
	}
	if (input.propel_backward)
	{
		rigid_body->applyCentralImpulse(quatRotate(rotation, btVector3(-max_speed, 0, 0) * dt));
	}

	const float max_rotation_speed = 20 * glm::pi<float>();

	if (input.roll_right)
	{
		rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(max_rotation_speed, 0, 0)) * dt);
	}
	if (input.roll_left)
	{
		rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(-max_rotation_speed, 0, 0)) * dt);
	}

	if (input.pitch_up)
	{
		rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(0, 0, max_rotation_speed)) * dt);
	}

	if (input.pitch_down)
	{
		rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(0, 0, -max_rotation_speed)) * dt);
	}
}

void Ship::Collision(ICollidable* obj)
{
	//do nothing
}
