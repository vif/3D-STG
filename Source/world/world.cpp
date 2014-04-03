#include "world.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>


World::PhysicsWorld::PhysicsWorld()
{
	_broadphase = std::make_unique<btDbvtBroadphase>();
	_collision_configuration = std::make_unique<btDefaultCollisionConfiguration>();
	_dispatcher = std::make_unique<btCollisionDispatcher>(_collision_configuration.get());
	_solver = std::make_unique<btSequentialImpulseConstraintSolver>();

	world = std::make_unique<btDiscreteDynamicsWorld>(_dispatcher.get(), _broadphase.get(), _solver.get(),  _collision_configuration.get());
	world->setGravity({ 0, 0, 0 });
}

void UpdateCallBackShim(btDynamicsWorld *world, btScalar timeStep)
{
	World *w = static_cast<World *>(world->getWorldUserInfo());
	w->Update(timeStep);
}

World::World() :
enemy_manager(physics_world.world.get())
{
	physics_world.world->addRigidBody(ship.rigid_body.get(), 0, 0);

	physics_world.world->setInternalTickCallback(UpdateCallBackShim, static_cast<void *>(this));
}

World::~World()
{
	physics_world.world->removeRigidBody(ship.rigid_body.get());
	enemy_manager.RemoveRigidBodiesFromWorld(physics_world.world.get());
}

void World::Update(double dt)
{
	//UPDATE THE WORLD!
	environment.Update(dt, this);

	ship.Update(dt, this);

	enemy_manager.Update(dt, this);

	camera.Update(dt, this);

	CollisionDetection();
}

void World::Render()
{
	auto camera_dir = camera.position + glm::rotate(camera.orientation, glm::vec3(1, 0, 0));
	auto camera_up = glm::rotate(camera.orientation, glm::vec3(0, 1, 0));
	auto viewMatrix = glm::lookAt(camera.position, camera_dir, camera_up);

	environment.Render(camera.position, viewMatrix, projectionMatrix);

	enemy_manager.Render(camera.position, viewMatrix, projectionMatrix);

	ship.Render(camera.position, viewMatrix, projectionMatrix);
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