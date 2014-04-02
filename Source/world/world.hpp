#pragma once

#include <environment/environment.hpp>
#include <player/ship.hpp>
#include <camera/camera.hpp>
#include <btBulletDynamicsCommon.h>
#include <object_types/enemy.hpp>


class World
{
public:
	World();

	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		std::unique_ptr<btDynamicsWorld> world;
	private:
		std::unique_ptr<btBroadphaseInterface> _broadphase;
		std::unique_ptr<btDefaultCollisionConfiguration> _collision_configuration;
		std::unique_ptr<btDispatcher> _dispatcher;
		std::unique_ptr<btSequentialImpulseConstraintSolver> _solver;
	} physics_world;

	Environment environment;
	Ship ship;
	std::list<std::unique_ptr<Enemy>> enemies;

	glm::mat4 projectionMatrix;

	Camera camera;

	void Update(double dt);
	void Render();
private:
	World(const World&) = delete;
};