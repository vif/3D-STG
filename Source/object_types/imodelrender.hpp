#pragma once

#include <glm/glm.hpp>

class IModelRender
{
public:
	virtual void Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix) = 0;
private:
};