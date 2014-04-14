#include "drawable.hpp"

void Drawable::Render(glm::vec3 camera_position, glm::mat4 model_matrix, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	model_pointer->draw(camera_position, model_matrix, view_matrix, projection_matrix);
}