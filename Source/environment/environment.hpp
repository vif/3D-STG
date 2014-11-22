#pragma once

#include <object_types/imodelrender.hpp>
#include "cylinder_grid.hpp"

class Environment : public IModelRender
{
public:
	Environment();

	void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
private:
	Environment(const Environment&) = delete;
	CylinderGrid cylinderGrid;
};