#include "ship.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <world/world.hpp>

Ship::Ship() :
model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d)
{
	model_pointer = &model;

	pose = std::make_unique<btDefaultMotionState>(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	
	auto shape = model.GetCollisionShape();

	btVector3 inertia;
	shape->calculateLocalInertia(weight, inertia);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(weight, pose.get(), shape, inertia);

	rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);

	rigid_body->activate(true);
}

void Ship::Update(double dt, World* world)
{
	rigid_body->applyCentralImpulse(btVector3(1, 0, 0));
}