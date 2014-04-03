#include "camera.hpp"
#include <world/world.hpp>
#include <glm/gtx/quaternion.hpp>

void Camera::Update(double dt, World* world)
{
	if (attachedToShip ^ world->input_manager.C_key)
	{
		btTransform transform;
		world->ship.pose->getWorldTransform(transform);

		auto ship_rot = transform.getRotation();
		auto ship_pos = transform.getOrigin() + quatRotate(ship_rot, btVector3(5, 0, 0));

		position = { ship_pos.x(), ship_pos.y(), ship_pos.z() };
		orientation = glm::quat(ship_rot.w(), ship_rot.x(), ship_rot.y(), ship_rot.z());
		orientation = glm::rotate(orientation, glm::pi<float>() * (world->input_manager.x_mouse / 2000.0f), glm::vec3(0, -1, 0));
		orientation = glm::rotate(orientation, glm::pi<float>() * (world->input_manager.y_mouse / 2000.0f), glm::vec3(0, 0, 1));
	}
	else
	{	
		position = glm::vec3(-21, 8, 0);
		orientation = glm::quat(1, 0, 0, 0);
	}
}