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

	auto movementspeed = 1000;
	auto follow_distance = 50;


	//pose->setWorldTransform(glm::, position));

	auto dir_ship = ship_position - position;

	//VELOCITY

	//get direction to ship, rotate by 90 degrees, make it's length the follow_distance and add it to the ship's position
	auto dest = ship_position + quatRotate(btQuaternion(90.0f, 0.0f, 0.0f), dir_ship).normalize() * follow_distance;

	//head towards the destination
	rigid_body->setLinearVelocity((dest - position).normalize() * movementspeed * dt);

	//TODO: always face ship
}

void BasicEnemy::Collision(ICollidable* obj)
{
	//do nothing
}
