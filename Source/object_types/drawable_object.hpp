#pragma once

#include <glm/glm.hpp>
#include <model/model.hpp>
#include "imodelrender.hpp"

class DrawableObject : public IModelRender
{
public:
	DrawableObject(glm::vec3 init_pos, glm::quat init_orientation, Model::Model* model);
	Model::Model* model_pointer;
	std::unique_ptr<btMotionState> pose;
	void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
private:
};