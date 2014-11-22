#pragma once

#include <object_types/icollidable.hpp>
#include <object_types/killable.hpp>
#include <object_types/iscriptable.hpp>
#include <object_types/moveable_object.hpp>
#include <attacks/basic_attack.hpp>

class Ship : public IScriptable, public ICollidable, public Killable
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

	std::unique_ptr<btMotionState> pose;
private:
	const glm::vec3 _init_pos = glm::vec3(10, 0, 0);
	const glm::quat _init_orientation = glm::quat();
	const double _init_weight = 100;

	Model::Model _model;
	Model::Model _basic_attack_model;

	std::unique_ptr<DrawableObject> _drawable;
	std::unique_ptr<MoveableObject> _moveable;

	std::list<std::unique_ptr<BasicAttack>> _basic_attacks;

	Ship(const Ship&) = delete;
	btDynamicsWorld* _physics_world;
};