#include "environment.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <glm/gtc/random.hpp>

Environment::Environment() :
cylider("Resources/models/environment/cylinders.obj", &Global::shader_manager->phong3d)
{
	const float max_distance = 1000.0;
	double num_cylinders = 1000;

#ifdef DEBUG
	num_cylinders /= 10; //reduces number of cylinders for debug builds
#endif 

	cylinders.resize(num_cylinders);
	for (auto& c : cylinders)
	{
		c.model_pointer = &cylider;
		c.position = glm::ballRand(max_distance);
		c.orientation = { glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f) };
	}
}

void Environment::Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	for (auto& c : cylinders)
	{
		c.Render(camera_position, view_matrix, projection_matrix);
	}
}