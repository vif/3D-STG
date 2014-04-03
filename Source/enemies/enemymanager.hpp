#pragma once

#include <object_types/scriptablephysicsobject.hpp>
#include <list>
#include "basic.hpp"

class EnemyManager : public ScriptablePhysicsObject
{
public:
	EnemyManager(btDynamicsWorld* world);

	Model::Model basic_enemy_model;

	std::list<std::unique_ptr<BasicEnemy>> basic_enemies;

	void RemoveRigidBodiesFromWorld(btDynamicsWorld* world);

	void Update(double dt, World* world) override;
	void Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
private:
};