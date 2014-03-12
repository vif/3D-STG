#pragma once

#include <glm/glm.hpp>

class IDrawableObject
{
public:
	virtual ~IDrawableObject() = default;
	virtual void render(double t, double dt, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) = 0;
	virtual void integrate(double t, double dt) = 0;
private:
};