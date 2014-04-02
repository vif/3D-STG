#pragma once

#include "imodelrender.hpp"
#include "iupdatable.hpp"
#include "drawable.hpp"
#include <glm/gtc/quaternion.hpp>

class SciptableObject : public Drawable, public IUpdatable, private IModelRender
{
public:
	glm::fvec3 position;
	glm::fquat orientation;
	virtual void IModelRender::Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
	virtual void IUpdatable::Update(double dt, World* world) = 0;
private:
};