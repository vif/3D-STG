#include "enemymanager.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <world/world.hpp>

EnemyManager::EnemyManager(btDynamicsWorld* physics_world, Ship* ship) :
_ship(ship),
_physics_world(physics_world),
basic_enemy_model("Resources/models/enemies/basic.dae", &Global::shader_manager->phong3d)
{
	basic_enemies.emplace_back(std::make_unique<BasicEnemy>(_ship, &basic_enemy_model, glm::vec3(100, 0, 0), glm::quat()));
	auto be = basic_enemies.back().get();
	be->moveable->rigid_body->setUserPointer(static_cast<ICollidable*>(be));
	be->moveable->rigid_body->setCollisionFlags(be->moveable->rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);


	void* a = be->moveable->rigid_body->getUserPointer();

	physics_world->addRigidBody(be->moveable->rigid_body.get());
}

void EnemyManager::RemoveRigidBodiesFromWorld()
{
	for (auto& b : basic_enemies)
	{
		_physics_world->removeRigidBody(b->moveable->rigid_body.get());
	}
}

void EnemyManager::Update(double dt)
{
	auto b = basic_enemies.begin();
	while (b != basic_enemies.end())
	{
		if ((*b)->alive)
		{
			(*b)->Update(dt);
			++b;
		}
		else
		{
			_physics_world->removeRigidBody((*b)->moveable->rigid_body.get());
			b = basic_enemies.erase(b);
		}
	}
}

void EnemyManager::Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	for (auto& b : basic_enemies)
	{
		b->Render(view_light_direction, view_matrix, projection_matrix);
	}
}