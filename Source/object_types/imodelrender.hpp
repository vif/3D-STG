#pragma once

#include <glm/glm.hpp>

class IModelRender
{
public:
	virtual void Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) = 0;
private:
};