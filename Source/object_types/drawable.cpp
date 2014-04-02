#include "drawable.hpp"

void Drawable::Render(glm::vec3 camera_position, glm::mat4 modelMatrix, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	model_pointer->draw(camera_position, modelMatrix, viewMatrix, projectionMatrix);
}