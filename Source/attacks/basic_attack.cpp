#include "basic_attack.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <utilities/MathConversions/math_conversions.hpp>

BasicAttack::BasicAttack(double damage, double expiration_time_delta, glm::vec3 init_position, glm::quat init_rotation, glm::vec3 direction, Model::Model* model)
{
	this->damage = damage;
	_direction = direction;
	_expiration_time_delta = expiration_time_delta;

	_model = model;

	_pose = std::make_unique<btDefaultMotionState>(btTransform(toQuat(init_rotation), toVec3(init_position)));
	_drawable = std::make_unique<DrawableObject>(_pose.get(), _model);
	moveable = std::make_unique<MoveableObject>(MoveableObject::ObjectType::SIMULATED, _pose.get(), _model->GetCollisionShape(), 10);

	moveable->rigid_body->setUserPointer(static_cast<ICollidable*>(this));
	moveable->rigid_body->setCollisionFlags(moveable->rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

void BasicAttack::Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix)
{
	_drawable->Render(view_light_direction, view_matrix, projection_matrix);
}

void BasicAttack::Update(double dt)
{
	if (_expiration_time_delta < 0)
	{
		active = false;
	}
	else
	{
		_expiration_time_delta -= dt;

		moveable->rigid_body->activate(true);

		moveable->rigid_body->setLinearVelocity(toVec3(_direction));
	}
}
