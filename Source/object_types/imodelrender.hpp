#pragma once

#include <glm/glm.hpp>

class IModelRender
{
public:
	virtual void Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix) = 0;
private:
};