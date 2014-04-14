#pragma once

#include <glm/glm.hpp>

class IModelRender
{
public:
	virtual void Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix) = 0;
private:
};