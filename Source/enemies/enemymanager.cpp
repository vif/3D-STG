#include "enemymanager.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <world/world.hpp>

EnemyManager::EnemyManager(btDynamicsWorld* world) :
basic_enemy_model("Resources/models/enemies/basic.dae", &Global::shader_manager->phong3d)
{
	basic_enemies.emplace_back(std::make_unique<BasicEnemy>());
	auto be = basic_enemies.front().get();
	be->model_pointer = &basic_enemy_model;
	be->pose = std::make_unique<btDefaultMotionState>(btTransform(btQuaternion(0, 0, 0, 1), btVector3(100, 0, 0)));
	//auto shape = basic_enemy_model.GetCollisionShape();
	auto shape = new btBoxShape(btVector3(10, 10, 10));
	btVector3 inertia = btVector3(10, 10, 10);
	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(10, be->pose.get(), shape, inertia);
	be->rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);
	world->addRigidBody(be->rigid_body.get(), 0, 0);
	be->rigid_body->setUserPointer(static_cast<void*>(this));
	be->rigid_body->setUserIndex(World::ObjetType::BASIC_ENEMY);
	be->rigid_body->setCollisionFlags(be->rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

void EnemyManager::RemoveRigidBodiesFromWorld(btDynamicsWorld* world)
{
	for (auto& b : basic_enemies)
	{
		world->removeRigidBody(b->rigid_body.get());
	}
}

void EnemyManager::Update(double dt, World* world)
{
	//TODO: need to remove rigid bodies when no longer alive
	for (auto& b : basic_enemies)
	{
		b->Update(dt, world);
	}
}

void EnemyManager::Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	for (auto& b : basic_enemies)
	{
		b->Render(camera_position, viewMatrix, projectionMatrix);
	}
}