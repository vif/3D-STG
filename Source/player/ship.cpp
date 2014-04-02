#include "ship.hpp"

#include <glm.hpp>
#include <utilities/ShaderManager/shadermanager.hpp>

Ship::Ship() :
model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d)
{
	position = { 0, 0, 0 };
}

void Ship::integrate(double t, double dt)
{
}

void Ship::render(double t, double dt, glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	glm::mat4 model_rotation = glm::toMat4(orientation);
	glm::mat4 model_position = glm::translate(glm::mat4(), position);

	auto modelMatrix = model_position * model_rotation;

	model.draw(camera_position, modelMatrix, viewMatrix, projectionMatrix);
}