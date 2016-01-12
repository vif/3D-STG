#pragma once

#include <object_types/iscriptable.hpp>
#include <object_types/moveable_object.hpp>
#include <object_types/icollidable.hpp>
#include <object_types/drawable_object.hpp>
#include <model/model.hpp>
#include <glm/common.hpp>

class BasicAttack : public IScriptable, public ICollidable
{
public:
	BasicAttack(double damage, double expiration_time_delta, glm::vec3 init_position, glm::quat init_rotation, glm::vec3 direction, Model::Model* model);
	void Update(double dt) override;
	void Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix) override;
	void Collision(ICollidable*) override {}
	bool active = true;
	double damage;
	std::unique_ptr<MoveableObject> moveable;
private:
	double _expiration_time_delta;
	glm::vec3 _direction;

	Model::Model* _model;
	std::unique_ptr<btMotionState> _pose;
	std::unique_ptr<DrawableObject> _drawable;
};