#include "camera.hpp"
#include <glm/gtx/quaternion.hpp>
#include <ship/ship.hpp>

void Camera::Update(double dt)
{
	double mouse_sensitivity = 20.0;

	if (input.follow_ship)
	{
		btTransform transform;
		_ship->pose->getWorldTransform(transform);

		auto ship_rot = transform.getRotation();
		auto ship_pos = transform.getOrigin() + quatRotate(ship_rot, btVector3(5, 0, 0));

		position = { ship_pos.x(), ship_pos.y(), ship_pos.z() };

		camera_follow_orientation = glm::rotate(camera_follow_orientation, (float)(input.mouse_delta_x * dt / mouse_sensitivity), glm::vec3(0, -1, 0));
		camera_follow_orientation = glm::rotate(camera_follow_orientation, (float)(input.mouse_delta_y * dt / mouse_sensitivity), glm::vec3(0, 0, 1));

		//compose the ship orientation with the camera orientation
		orientation = glm::quat(ship_rot.w(), ship_rot.x(), ship_rot.y(), ship_rot.z()) * camera_follow_orientation;
	}
	else
	{
		free_move_orientation = glm::rotate(free_move_orientation, (float)(input.mouse_delta_x * dt / mouse_sensitivity), glm::vec3(0, -1, 0));
		free_move_orientation = glm::rotate(free_move_orientation, (float)(input.mouse_delta_y * dt / mouse_sensitivity), glm::vec3(0, 0, 1));

		double movementspeed = 50;

		if (input.move_forward)
		{
			free_move_position += glm::rotate(free_move_orientation, glm::vec3(movementspeed, 0, 0) * (float)dt);
		}

		if (input.move_backward)
		{
			free_move_position += glm::rotate(free_move_orientation, glm::vec3(-movementspeed, 0, 0) * (float)dt);
		}

		if (input.strafe_left)
		{
			free_move_position += glm::rotate(free_move_orientation, glm::vec3(0, 0, -movementspeed) * (float)dt);
		}

		if (input.strafe_right)
		{
			free_move_position += glm::rotate(free_move_orientation, glm::vec3(0, 0, movementspeed) * (float)dt);
		}

		position = free_move_position;
		orientation = free_move_orientation;
	}

	//reset any changes in the mouse positions we might have accumulated
	input.mouse_delta_x = 0;
	input.mouse_delta_y = 0;
}