#include "scriptablephysicsobject.hpp"

void ScriptablePhysicsObject::Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	glm::mat4 ATTRIBUTE_ALIGNED16(model_matrix);

	btTransform transform;
	pose->getWorldTransform(transform);
	transform.getOpenGLMatrix(glm::value_ptr(model_matrix));

	Drawable::Render(camera_position, model_matrix, view_matrix, projection_matrix);
}