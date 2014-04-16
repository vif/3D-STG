#pragma once

#include <object_types/scriptable_object.hpp>

class Ship : private Model::Model, public ScriptableObject //crappy multiple inheritance because base class get initialized (in order) before non-static members, so couldn't have Model as a member
{
public:
	Ship();

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