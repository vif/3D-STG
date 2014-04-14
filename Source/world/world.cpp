#include "world.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <utilities/ShaderManager/shadermanager.hpp>


void UpdateCallBackShim(btDynamicsWorld *world, btScalar timeStep)
{
	World *w = static_cast<World *>(world->getWorldUserInfo());
	w->Update(timeStep);
}

World::World() :
input_manager(this)
{
	camera = std::make_unique<Camera>(&ship);
	enemy_manager = std::make_unique<EnemyManager>(physics_world.world.get(), &ship);

	physics_world.world->addRigidBody(ship.rigid_body.get(), 0, 0);

	physics_world.world->setInternalTickCallback(UpdateCallBackShim, static_cast<void *>(this));
}

World::~World()
{
	physics_world.world->removeRigidBody(ship.rigid_body.get());
	enemy_manager->RemoveRigidBodiesFromWorld();
}


World::PhysicsWorld::PhysicsWorld() :
debug_drawer(&Global::shader_manager->simple)
{
	_broadphase = std::make_unique<btDbvtBroadphase>();
	_collision_configuration = std::make_unique<btDefaultCollisionConfiguration>();
	_dispatcher = std::make_unique<btCollisionDispatcher>(_collision_configuration.get());
	_solver = std::make_unique<btSequentialImpulseConstraintSolver>();

	world = std::make_unique<btDiscreteDynamicsWorld>(_dispatcher.get(), _broadphase.get(), _solver.get(),  _collision_configuration.get());
	world->setGravity({ 0, 0, 0 });
	world->setDebugDrawer(&debug_drawer);
}

void World::Update(double dt)
{
	//UPDATE THE WORLD!
	ship.Update(dt);

	enemy_manager->Update(dt);

	camera->Update(dt);

	CollisionDetection();
}

void World::Render()
{
	auto camera_dir = camera->position + glm::rotate(camera->orientation, glm::vec3(1, 0, 0));
	auto camera_up = glm::rotate(camera->orientation, glm::vec3(0, 1, 0));
	auto view_matrix = glm::lookAt(camera->position, camera_dir, camera_up);

	auto projection_matrix = display_info.getProjectionMatrix();

	environment.Render(camera->position, view_matrix, projection_matrix);

	enemy_manager->Render(camera->position, view_matrix, projection_matrix);

	ship.Render(camera->position, view_matrix, projection_matrix);

	if (input.draw_physics_debug)
	{
		physics_world.world->debugDrawWorld(); //setups up the data to draw
		physics_world.debug_drawer.drawAndClear(view_matrix, projection_matrix);
	}
}

void World::CollisionDetection()
{
	int numManifolds = physics_world.world->getDispatcher()->getNumManifolds();
	for (int i = 0; i < numManifolds; i++)
	{
		btPersistentManifold* contactManifold = physics_world.world->getDispatcher()->getManifoldByIndexInternal(i);
		auto obA = static_cast<const btCollisionObject*>(contactManifold->getBody0());
		auto obB = static_cast<const btCollisionObject*>(contactManifold->getBody1());
	}
}