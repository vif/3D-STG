#pragma once

#include <object_types/iscriptable.hpp>
#include <object_types/icollidable.hpp>
#include <object_types/killable.hpp>
#include <object_types/moveable_object.hpp>
#include <object_types/drawable_object.hpp>
#include <model/model.hpp>
#include <ship/ship.hpp>

class BasicEnemy : public IScriptable, public ICollidable, public Killable
{
public:
	BasicEnemy(Ship* ship, Model::Model* model, glm::vec3 init_pos, glm::quat init_orientation);
	void Update(double dt) override;
	void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
	void Collision(ICollidable*) override;

	std::unique_ptr<btMotionState> pose;
	std::unique_ptr<MoveableObject> moveable;
private:
	Ship* _ship;

	std::unique_ptr<DrawableObject> _drawable;
};