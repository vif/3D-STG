#include "camera.hpp"
#include <glm/gtx/quaternion.hpp>
#include <ship/ship.hpp>

void Camera::Update(double dt)
{
	//handle toggling between free move and following the ship
	if (input.toggle_ship_follow)
	{
		if (!_follow_ship)
		{
			//resets the rotations
			_pitch = glm::quat();
			_yaw = glm::quat();
		}

		//toggle whether we follow or not
		_follow_ship = !_follow_ship;

		//set the input to indicate we have handled the toggle
		input.toggle_ship_follow = false;
	}

	double mouse_sensitivity = 200.0;

	//keep pitch and yaw separate so we don't experience loss of significance.
	_yaw = glm::rotate(_yaw, (float)(input.mouse_delta_x / mouse_sensitivity), glm::vec3(0, -1, 0));
	//TODO: make clamping less ugly
	auto proposed_pitch = glm::rotate(_pitch, (float)(input.mouse_delta_y / mouse_sensitivity), glm::vec3(0, 0, 1));
	if (glm::abs(glm::eulerAngles(proposed_pitch)).z < pitch_clamp)
	{
		_pitch = proposed_pitch;
	}

	//since the deltas are cumulative reset them
	input.mouse_delta_x = 0;
	input.mouse_delta_y = 0;

	if (_follow_ship) //attached to ship
	{
		btTransform transform;
		_ship->pose->getWorldTransform(transform);

		auto ship_rot = transform.getRotation();
		auto ship_pos = transform.getOrigin() + quatRotate(ship_rot, btVector3(5, 0, 0));

		position = { ship_pos.x(), ship_pos.y(), ship_pos.z() };

		//compose the ship orientation with the camera orientation
		orientation = _yaw * glm::quat(ship_rot.w(), ship_rot.x(), ship_rot.y(), ship_rot.z()) * _pitch;
	}
	else //free move
	{
		double movementspeed = 50;

		if (input.move_forward)
		{
			position += glm::rotate(orientation, glm::vec3(movementspeed, 0, 0) * (float)dt);
		}

		if (input.move_backward)
		{
			position += glm::rotate(orientation, glm::vec3(-movementspeed, 0, 0) * (float)dt);
		}

		if (input.strafe_left)
		{
			position += glm::rotate(orientation, glm::vec3(0, 0, -movementspeed) * (float)dt);
		}

		if (input.strafe_right)
		{
			position += glm::rotate(orientation, glm::vec3(0, 0, movementspeed) * (float)dt);
		}

		orientation = _yaw * _pitch;
	}
}