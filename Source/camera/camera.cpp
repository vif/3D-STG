#include "camera.hpp"
#include <world/world.hpp>

void Camera::Update(double dt, World* world)
{
	if (attachedToShip)
	{
		btTransform transform;
		world->ship.pose->getWorldTransform(transform);

		auto ship_pos = transform.getOrigin();
		auto ship_rot = transform.getRotation();

		position = { ship_pos.x() - 21.0, ship_pos.y() + 8, ship_pos.z() };
		orientation = glm::quat(ship_rot.w(), ship_rot.x(), ship_rot.y(), ship_rot.z());
	}
}