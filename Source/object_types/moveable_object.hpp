#pragma once

#include <model/model.hpp>
#include <memory>
#include <btBulletDynamicsCommon.h>

class MoveableObject
{
public:
	enum class ObjectType{UNSIMULATED, SIMULATED} type;
	MoveableObject(ObjectType type, btMotionState* pose, btCollisionShape* collision_shape, double weight = 0.0);
	std::unique_ptr<btRigidBody> rigid_body;
private:
	btMotionState* _pose;
};