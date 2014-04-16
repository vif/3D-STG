#include "basic.hpp"

void BasicEnemy::Update(double dt)
{
	rigid_body->activate(true);

	btTransform ship_transform;
	_ship->pose->getWorldTransform(ship_transform);
	auto ship_position = ship_transform.getOrigin();

	btTransform transform;
	pose->getWorldTransform(transform);
	auto position = transform.getOrigin();

	auto movementspeed = 10;

	rigid_body->applyCentralForce((ship_position - position).normalize() * movementspeed * dt);
}