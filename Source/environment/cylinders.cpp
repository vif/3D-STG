#include "cylinders.hpp"

void Cylinder::render(double t, double dt, glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	glm::mat4 model_rotation = glm::toMat4(orientation);
	glm::mat4 model_position = glm::translate(glm::mat4(), position);

	auto modelMatrix = model_position * model_rotation;

	model->draw(camera_position, modelMatrix, viewMatrix, projectionMatrix);
}