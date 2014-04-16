#pragma once

#include "iupdatable.hpp"
#include "drawable_object.hpp"
#include <memory>
#include <btBulletDynamicsCommon.h>

class ScriptableObject : public DrawableObject, public IUpdatable
{
public:
	enum class ObjectType{UNSIMULATED, SIMULATED}; //simulated have collisions shapes and are handled by physics world, unsimulated don't
	ScriptableObject(ObjectType type, glm::vec3 init_pos, glm::quat init_orientation, Model::Model* model, double weight = 0.0);
	std::unique_ptr<btRigidBody> rigid_body;
	virtual void IUpdatable::Update(double dt) = 0;
private:
	std::unique_ptr<btEmptyShape> _empty_shape; //just in-case we need it for unsimulated objects
};