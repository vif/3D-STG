#pragma once

#include "imodelrender.hpp"
#include "iupdatable.hpp"
#include "drawable.hpp"
#include <memory>
#include <btBulletDynamicsCommon.h>

class ScriptablePhysicsObject : public Drawable, public IUpdatable, private IModelRender
{
public:
	std::unique_ptr<btDefaultMotionState> pose;
	std::unique_ptr<btRigidBody> rigid_body;
	virtual void IModelRender::Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
	virtual void IUpdatable::Update(double dt, World* world) = 0;
private:
};