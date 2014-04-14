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
	virtual void IModelRender::Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
	virtual void IUpdatable::Update(double dt) = 0;
private:
};