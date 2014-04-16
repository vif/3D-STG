#include "drawable_object.hpp"
#include <utilities/MathConversions/math_conversions.hpp>

DrawableObject::DrawableObject(glm::vec3 init_pos, glm::quat init_orientation, Model::Model* model)
{
	model_pointer = model;
	pose = std::make_unique<btDefaultMotionState>(btTransform(toQuat(init_orientation), toVec3(init_pos)));
}

void DrawableObject::Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	btTransform transform;
	pose->getWorldTransform(transform);

	auto model_matrix = toMat4(transform);

	model_pointer->draw(camera_position, model_matrix, view_matrix, projection_matrix);
}
