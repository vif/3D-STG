#include "environment.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <glm/gtc/random.hpp>

Environment::Environment() :
cylider("Resources/models/environment/cylinders.obj", &Global::shader_manager->phong3d)
{
	const float max_distance = 1000.0;
	const double num_cylinders = 100;

	cylinders.resize(num_cylinders);
	for (auto& c : cylinders)
	{
		c.model_pointer = &cylider;
		c.position = glm::ballRand(max_distance);
		c.orientation = { glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f) };
	}
}

void Environment::Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	for (auto& c : cylinders)
	{
		c.Render(camera_position, viewMatrix, projectionMatrix);
	}
}