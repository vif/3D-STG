#include "ship.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <world/world.hpp>

Ship::Ship() :
model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d)
{
	model_pointer = &model;

	pose = std::make_unique<btDefaultMotionState>(btTransform(btQuaternion(0, 0, 0, 1), btVector3(10, 0, 0)));

	//auto shape = model.GetCollisionShape();
	auto shape = new btBoxShape(btVector3(10, 10, 10));

	btVector3 inertia = btVector3(10, 10, 10);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(weight, pose.get(), shape, inertia);

	rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);
	rigid_body->setUserIndex(World::ObjetType::SHIP);
	rigid_body->setUserPointer(static_cast<void *>(this));
	rigid_body->setCollisionFlags(rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

#include <iostream>

void Ship::Update(double dt)
{
	rigid_body->activate(true);

	auto transform = rigid_body->getWorldTransform();
	auto rotation = transform.getRotation();

	const float max_speed = 100;

	if (input.propel_forward)
	{
		rigid_body->applyCentralForce(quatRotate(rotation, btVector3(max_speed, 0, 0) * dt));
	}
	if (input.propel_backward)
	{
		rigid_body->applyCentralForce(quatRotate(rotation, btVector3(-max_speed, 0, 0) * dt));
	}

	const float max_rotation_speed = glm::pi<float>();

	if (input.roll_right)
	{
		rigid_body->applyTorque(quatRotate(rotation, btVector3(max_rotation_speed, 0, 0)) * dt);
	}
	if (input.roll_left)
	{
		rigid_body->applyTorque(quatRotate(rotation, btVector3(-max_rotation_speed, 0, 0)) * dt);
	}

	if (input.pitch_up)
	{
		rigid_body->applyTorque(quatRotate(rotation, btVector3(0, 0, max_rotation_speed)) * dt);
	}

	if (input.pitch_down)
	{
		rigid_body->applyTorque(quatRotate(rotation, btVector3(0, 0, -max_rotation_speed)) * dt);
	}
}