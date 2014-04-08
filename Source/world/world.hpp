#pragma once

#include <btBulletDynamicsCommon.h>
#include <environment/environment.hpp>
#include <player/ship.hpp>
#include <camera/camera.hpp>
#include <enemies/enemymanager.hpp>
#include <input_manager/input_manager.hpp>
#include <utilities/BulletDebugDrawer/debug_drawer.hpp>

class World
{
public:
	World();
	~World();

	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		std::unique_ptr<btDynamicsWorld> world;
		btOGLDebugDrawer debug_drawer;
	private:
		std::unique_ptr<btBroadphaseInterface> _broadphase;
		std::unique_ptr<btDefaultCollisionConfiguration> _collision_configuration;
		std::unique_ptr<btDispatcher> _dispatcher;
		std::unique_ptr<btSequentialImpulseConstraintSolver> _solver;
	} physics_world;

	Environment environment;
	Ship ship;
	EnemyManager enemy_manager;

	glm::mat4 projectionMatrix;

	Camera camera;

	enum ObjetType{SHIP, BASIC_ENEMY};
	void Update(double dt);
	void Render();

	void CollisionDetection();

	InputManager input_manager;
private:
	World(const World&) = delete;
};