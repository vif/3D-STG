#include "scriptable_object.hpp"
#include <utilities/MathConversions/math_conversions.hpp>


ScriptableObject::ScriptableObject(ObjectType type, glm::vec3 init_pos, glm::quat init_orientation, Model::Model* model, double weight) :
DrawableObject(init_pos, init_orientation, model)
{
	pose = std::make_unique<btDefaultMotionState>(btTransform(toQuat(init_orientation), toVec3(init_pos)));

	btCollisionShape* shape;
	btVector3 inertia;
	if (type == ObjectType::SIMULATED)
	{
		shape = model->GetCollisionShape();
		shape->calculateLocalInertia(weight, inertia);
		assert(inertia != btVector3(0, 0, 0));
	}
	else
	{
		_empty_shape = std::make_unique<btEmptyShape>();
		shape = _empty_shape.get();
	}

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(weight, pose.get(), shape, inertia);

	rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);
}