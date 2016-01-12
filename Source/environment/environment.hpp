#pragma once

#include <object_types/imodelrender.hpp>
#include "cylinder_grid.hpp"

class Environment : public IModelRender
{
public:
	Environment();

	void Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix) override;
private:
	Environment(const Environment&) = delete;
	CylinderGrid cylinderGrid;
};