#pragma once

#include <object_types/scriptablephysicsobject.hpp>

class Ship : public ScriptablePhysicsObject
{
public:
	Ship();

	Model::Model model;

	const float weight = 100;

	void Update(double dt) override;

	struct Input
	{
		bool 
			propel_forward,
			propel_backward,
			pitch_up,
			pitch_down,
			roll_left,
			roll_right
			= false;
	} input;
private:
	Ship(const Ship&) = delete;
};