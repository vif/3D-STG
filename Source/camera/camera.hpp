#pragma once

#include <object_types/scriptableobject.hpp>

class Ship;

class Camera : public SciptableObject
{
public:
	Camera(Ship* ship) : _ship(ship){}

	glm::vec3 free_move_position;
	glm::quat free_move_orientation;

	glm::quat camera_follow_orientation;

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
	} input;
private:
	Ship* _ship;
	bool _follow_ship = false;
};