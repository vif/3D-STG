#pragma once

#include <object_types/imodelrender.hpp>
#include <object_types/iupdatable.hpp>
#include "basic.hpp"
#include <ship/ship.hpp>

class EnemyManager : public IModelRender, public IUpdatable
{
public:
	EnemyManager(btDynamicsWorld* physics_world, Ship* ship);

	Model::Model basic_enemy_model;

	std::vector<std::unique_ptr<BasicEnemy>> basic_enemies;

	void RemoveRigidBodiesFromWorld();

	void Update(double dt) override;
	void Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix) override;
private:
	Ship* _ship;
	btDynamicsWorld* _physics_world;
};