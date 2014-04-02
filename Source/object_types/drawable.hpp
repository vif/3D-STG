#pragma once

#include <glm/glm.hpp>
#include <model/model.hpp>

class Drawable
{
public:
	void Render(glm::vec3 camera_position, glm::mat4 modelMatrix, glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
	Model::Model* model_pointer;
private:
};