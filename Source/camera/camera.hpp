#pragma once

#include <object_types/moveable_object.hpp>
#include <object_types/iupdatable.hpp>
#include <ship/ship.hpp>

class Camera : public IUpdatable
{
public:
	Camera(Ship* ship);

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
	const float pitch_clamp = glm::radians(89.0f);

	std::unique_ptr<btMotionState> pose;
	std::unique_ptr<MoveableObject> moveable;
private:
	Camera(const Camera&) = delete;

	Ship* _ship;

	bool _follow_ship = false;

	//rotations stored separately to avoid loss of significance
	glm::quat _pitch;
	glm::quat _yaw;

	std::unique_ptr<btEmptyShape> _empty_shape;
};