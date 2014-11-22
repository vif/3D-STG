#pragma once

#include <model/model.hpp>
#include <object_types/imodelrender.hpp>
#include <utilities/ShaderManager/shadermanager.hpp>


class CylinderGrid : public IModelRender
{
public:
	CylinderGrid();
	void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix);
private:
	const int _num = 1000;
	const int _spread_distance = 1000;
	const int _line_radius = 500;

	oglplus::Program _program;
	std::unique_ptr<Model::Model> _model;

	oglplus::Uniform<oglplus::Vec4f> _view_light_direction_uniform;
	oglplus::Uniform<oglplus::Mat4f> _view_matrix_uniform;
	oglplus::Uniform<oglplus::Mat4f> _view_projection_matrix_uniform;
	oglplus::Buffer _line_positions;

	CylinderGrid(const CylinderGrid&) = delete;
};
