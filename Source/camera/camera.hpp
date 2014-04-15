#pragma once

#include <object_types/scriptableobject.hpp>

class Ship;

class Camera : public SciptableObject
{
public:
	Camera(Ship* ship) : _ship(ship){}

	void Update(double dt) override;

	struct
	{
		bool toggle_ship_follow = false;

		double mouse_delta_x = 0;
		double mouse_delta_y = 0;

		bool move_forward = false;
		bool move_backward = false;
		bool strafe_left = false;
		bool strafe_right = false;
		bool move_up = false;
		bool move_down = false;
	} input;

	//clamps the pitch (up and down viewing)
	const float pitch_clamp = glm::radians(80.0f);
private:
	Ship* _ship;

	bool _follow_ship = false;

	//rotations stored separately to avoid loss of significance
	glm::quat _pitch;
	glm::quat _yaw;
};