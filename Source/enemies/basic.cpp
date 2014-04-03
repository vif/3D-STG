#include "basic.hpp"

#include <world/world.hpp>


void BasicEnemy::Update(double dt, World* world)
{
	rigid_body->activate(true);

	btTransform ship_transform;
	world->ship.pose->getWorldTransform(ship_transform);
	auto ship_position = ship_transform.getOrigin();

	btTransform transform;
	pose->getWorldTransform(transform);
	auto position = transform.getOrigin();

	rigid_body->applyCentralForce((ship_position - position).normalize() * movementspeed * dt);
}