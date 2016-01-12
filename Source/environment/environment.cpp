#include "environment.hpp"

Environment::Environment()
{
}

void Environment::Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix)
{
	cylinderGrid.Render(view_light_direction, view_matrix, projection_matrix);
}