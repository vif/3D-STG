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
	Ship ship;
	//camera & input manager need reference to ship, so forward declare them
	std::unique_ptr<Camera> camera;
	std::unique_ptr<EnemyManager> enemy_manager;

	enum ObjetType{SHIP, BASIC_ENEMY};
	void Update(double dt);
	void Render();

	void CollisionDetection();

	InputManager input_manager;
	DisplayInfo display_info;

	struct Input
	{
		bool draw_physics_debug = false;
	} input;
private:
	World(const World&) = delete;
};