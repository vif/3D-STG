#include "camera.hpp"
#include <glm/gtx/quaternion.hpp>
#include <ship/ship.hpp>
#include <utilities/MathConversions/math_conversions.hpp>


Camera::Camera(Ship* ship)
{
	_ship = ship;
	_empty_shape = std::make_unique<btEmptyShape>();
	pose = std::make_unique<btDefaultMotionState>();
	moveable = std::make_unique<MoveableObject>(MoveableObject::ObjectType::SIMULATED, pose.get(), _empty_shape.get());
}

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
		auto ship_offset = btVector3(-5, 5, 0);
		auto ship_pos = transform.getOrigin() + quatRotate(ship_rot, ship_offset);

		//compose the ship orientation with the camera orientation
		auto orientation = toQuat(ship_rot) * _yaw  * _pitch;
		pose->setWorldTransform(btTransform(toQuat(orientation), ship_pos));
	}
	else //free move
	{
		btTransform transform;
		pose->getWorldTransform(transform);
		auto position = toVec3(transform.getOrigin());
		auto orientation = toQuat(transform.getRotation());

		double movementspeed = 100;

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

		if (input.move_up)
		{
			position += glm::rotate(orientation, glm::vec3(0, movementspeed, 0) * (float)dt);
		}

		if (input.move_down)
		{
			position += glm::rotate(orientation, glm::vec3(0, -movementspeed, 0) * (float)dt);
		}

		pose->setWorldTransform(btTransform(toQuat(_yaw * _pitch), toVec3(position)));
	}
}
