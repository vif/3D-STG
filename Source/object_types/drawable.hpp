#pragma once

#include <glm/glm.hpp>
#include <model/model.hpp>

class Drawable
{
public:
	void Render(glm::vec3 camera_position, glm::mat4 model_matrix, glm::mat4 view_matrix, glm::mat4 projection_matrix);
	Model::Model* model_pointer;
private:
};