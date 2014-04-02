#include "scriptablephysicsobject.hpp"

void ScriptablePhysicsObject::Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	glm::mat4 ATTRIBUTE_ALIGNED16(modelMatrix);

	btTransform transform;
	pose->getWorldTransform(transform);
	transform.getOpenGLMatrix(glm::value_ptr(modelMatrix));

	Drawable::Render(camera_position, modelMatrix, viewMatrix, projectionMatrix);
}