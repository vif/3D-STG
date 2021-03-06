#pragma once

#include <btBulletDynamicsCommon.h>
#include <environment/environment.hpp>
#include <ship/ship.hpp>
#include <camera/camera.hpp>
#include <enemies/enemymanager.hpp>
#include <input_manager/input_manager.hpp>
#include <display_info/display_info.hpp>
#include <utilities/BulletDebugDrawer/bullet_debug_drawer.hpp>

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

	std::unique_ptr<Ship> ship;
	std::unique_ptr<Camera> camera;
	std::unique_ptr<EnemyManager> enemy_manager;

	void Update(double dt);
	void Render();

	void CollisionDetection();

	InputManager input_manager;
	DisplayInfo display_info;

	glm::vec4 light_origin = glm::vec4(1, 1, 1, 0);

	struct
	{
		bool draw_physics_debug = false;
	} input;
private:
	World(const World&) = delete;
};