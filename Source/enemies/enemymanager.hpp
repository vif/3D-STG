#pragma once

#include <object_types/imodelrender.hpp>
#include <object_types/iupdatable.hpp>
#include <list>
#include "basic.hpp"
#include <ship/ship.hpp>

class EnemyManager : public IModelRender, public IUpdatable
{
public:
	EnemyManager(btDynamicsWorld* physics_world, Ship* ship);

	Model::Model basic_enemy_model;

	std::list<std::unique_ptr<BasicEnemy>> basic_enemies;

	void RemoveRigidBodiesFromWorld();

	void Update(double dt) override;
	void Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
private:
	Ship* _ship;
	btDynamicsWorld* _physics_world;
};