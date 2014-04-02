#include "ship.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <world/world.hpp>

Ship::Ship() :
model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d)
{
	model_pointer = &model;

	pose = std::make_unique<btDefaultMotionState>();
	
	auto shape = model.GetCollisionShape();

	btVector3 inertia(1, 1, 1);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(weight, pose.get(), shape, inertia);

	rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);
}

void Ship::Update(double dt, World* world)
{
}