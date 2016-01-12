#include "drawable_object.hpp"
#include <utilities/MathConversions/math_conversions.hpp>

DrawableObject::DrawableObject(btMotionState* pose, Model::Model* model) :
view_light_direction_uniform(*model->program, "ViewLightDirection"),
normal_matrix_uniform(*model->program, "NormalMatrix"),
model_view_matrix_uniform(*model->program, "ModelViewMatrix"),
model_view_projection_matrix_uniform(*model->program, "ModelViewProjectionMatrix"),
_pose(pose),
_model(model)
{
}

void DrawableObject::Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix)
{
	btTransform transform;
	_pose->getWorldTransform(transform);

	auto model_matrix = toMat4(transform);

	auto model_view_matrix = view_matrix * model_matrix;
	auto normal_matrix = glm::transpose(glm::inverse(model_view_matrix));
	auto model_view_projection_matrix = projection_matrix * model_view_matrix;

	_model->program->Use();

	view_light_direction_uniform.Set(view_light_direction);
	normal_matrix_uniform.Set(normal_matrix);
	model_view_matrix_uniform.Set(model_view_matrix);
	model_view_projection_matrix_uniform.Set(model_view_projection_matrix);

	_model->draw();

	oglplus::Program::UseNone();
}
