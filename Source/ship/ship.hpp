#pragma once

#include <object_types/scriptable_object.hpp>
#include <object_types/icollidable.hpp>
#include <object_types/killable.hpp>
#include <attacks/basic_attack.hpp>

class Ship : private Model::Model, public ScriptableObject, public ICollidable, public Killable //crappy multiple inheritance because base class get initialized (in order) before non-static members, so couldn't have Model as a member
{
public:
	Ship(btDynamicsWorld* physics_world);
	~Ship();

	void Update(double dt) override;

	void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;

	void Collision(ICollidable*) override;

	struct
	{
		bool 
			propel_forward,
			propel_backward,
			pitch_up,
			pitch_down,
			roll_left,
			roll_right,
			shoot
			= false;
	} input;
private:
	Ship(const Ship&) = delete;
	std::list<std::unique_ptr<BasicAttack>> _basic_attacks;
	btDynamicsWorld* _physics_world;
};