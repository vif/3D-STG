#pragma once

#include <glm/glm.hpp>
#include <model/model.hpp>
#include "imodelrender.hpp"

class DrawableObject : public IModelRender
{
public:
	DrawableObject(btMotionState* pose, Model::Model* model);

	void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
private:
	btMotionState* _pose;
	Model::Model* _model;

	oglplus::Uniform<oglplus::Vec4f> view_light_direction_uniform;
	oglplus::Uniform<oglplus::Mat4f> normal_matrix_uniform;
	oglplus::Uniform<oglplus::Mat4f> model_view_matrix_uniform;
	oglplus::Uniform<oglplus::Mat4f> model_view_projection_matrix_uniform;
};