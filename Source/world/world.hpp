#pragma once

#include <environment/environment.hpp>
#include <player/ship.hpp>
#include <glm.hpp>
#include <stl.hpp>
#include <btBulletDynamicsCommon.h>

class World
{
public:
	World();

	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		std::unique_ptr<btCollisionWorld> world;
	private:
		std::unique_ptr<btBroadphaseInterface> _broadphase;
		std::unique_ptr<btDefaultCollisionConfiguration> _collision_configuration;
		std::unique_ptr<btDispatcher> _dispatcher;
	} physics_world;

	Environment environment;
	Ship ship;
	std::list<std::unique_ptr<IEnemy>> enemies;

	glm::mat4 projectionMatrix;

	class Camera : public IPose{} camera;

	void integrate(double t, double dt);
	void render(double t, double dt);
private:
	World(const World&) = delete;
};