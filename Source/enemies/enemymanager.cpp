#include "enemymanager.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <ship/ship.hpp>

EnemyManager::EnemyManager(btDynamicsWorld* physics_world, Ship* ship) :
_ship(ship),
_physics_world(physics_world),
basic_enemy_model("Resources/models/enemies/basic.dae", &Global::shader_manager->phong3d)
{
	basic_enemies.emplace_back(std::make_unique<BasicEnemy>(_ship));
	auto be = basic_enemies.front().get();
	be->model_pointer = &basic_enemy_model;
	be->pose = std::make_unique<btDefaultMotionState>(btTransform(btQuaternion(0, 0, 0, 1), btVector3(100, 0, 0)));
	//auto shape = basic_enemy_model.GetCollisionShape();
	auto shape = new btBoxShape(btVector3(10, 10, 10));
	btVector3 inertia = btVector3(10, 10, 10);
	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(10, be->pose.get(), shape, inertia);
	be->rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);
	physics_world->addRigidBody(be->rigid_body.get(), 0, 0);
	be->rigid_body->setUserPointer(static_cast<void*>(this));
//	be->rigid_body->setUserIndex(World::ObjetType::BASIC_ENEMY);
	be->rigid_body->setCollisionFlags(be->rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

void EnemyManager::RemoveRigidBodiesFromWorld()
{
	for (auto& b : basic_enemies)
	{
		_physics_world->removeRigidBody(b->rigid_body.get());
	}
}

void EnemyManager::Update(double dt)
{
	//TODO: need to remove rigid bodies when no longer alive
	for (auto& b : basic_enemies)
	{
		b->Update(dt);
	}
}

void EnemyManager::Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	for (auto& b : basic_enemies)
	{
		b->Render(camera_position, view_matrix, projection_matrix);
	}
}