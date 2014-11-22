#include "moveable_object.hpp"

MoveableObject::MoveableObject(ObjectType type, btMotionState* pose, btCollisionShape* collision_shape, double weight)
{
	btCollisionShape* shape;
	btVector3 inertia;

	shape = collision_shape;

	if (type == ObjectType::SIMULATED)
	{
		shape->calculateLocalInertia(weight, inertia);
		assert(inertia != btVector3(0, 0, 0));
	}

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(weight, pose, shape, inertia);

	rigid_body = std::make_unique<btRigidBody>(rigidBodyCI);
}