#include "scriptableobject.hpp"
#include <glm/gtc/matrix_transform.hpp>

void SciptableObject::Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	glm::mat4 model_rotation = glm::mat4_cast(orientation);
	glm::mat4 model_position = glm::translate(glm::mat4(), position);

	auto modelMatrix = model_position * model_rotation;

	Drawable::Render(camera_position, modelMatrix, view_matrix, projection_matrix);
}