#pragma once

#include <interfaces.hpp>
#include <stl.hpp>
#include "cylinders.hpp"

class Environment : IDrawableObject
{
public:
	Environment();

	Model::Model cylinder;

	void IDrawableObject::integrate(double t, double dt) override;
	void IDrawableObject::render(double t, double dt, glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;

	std::vector<Cylinder> cylinders;
private:
};