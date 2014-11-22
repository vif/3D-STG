#include "environment.hpp"

Environment::Environment()
{
}

void Environment::Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	cylinderGrid.Render(view_light_direction, view_matrix, projection_matrix);
}