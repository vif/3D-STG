#pragma once

#include <object_types/scriptable_object.hpp>

class Ship : public ScriptableObject
{
public:
	Ship();

	Model::Model model;

	void Update(double dt) override;

	struct
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