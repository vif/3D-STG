#pragma once

#include <object_types/scriptablephysicsobject.hpp>
#include <list>
#include "basic.hpp"

class Ship;

class EnemyManager : public ScriptablePhysicsObject
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