#include "enemymanager.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <world/world.hpp>

EnemyManager::EnemyManager(btDynamicsWorld* physics_world, Ship* ship) :
_ship(ship),
_physics_world(physics_world),
basic_enemy_model("Resources/models/enemies/basic.dae", &Global::shader_manager->phong3d)
{
	basic_enemies.emplace_back(std::make_unique<BasicEnemy>(_ship, &basic_enemy_model, glm::vec3(100, 0, 0), glm::quat()));
	auto be = basic_enemies.front().get();
	be->rigid_body->setUserPointer(static_cast<void*>(this));
	be->rigid_body->setUserIndex(World::ObjetType::BASIC_ENEMY);
	be->rigid_body->setCollisionFlags(be->rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK); 

	physics_world->addRigidBody(be->rigid_body.get());
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