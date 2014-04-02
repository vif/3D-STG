#pragma once

#include <interfaces.hpp>
#include <model/model.hpp>

class Cylinder : public IDrawableObject, public IPose
{
public:
	Model::Model* model;

	void IDrawableObject::integrate(double t, double dt) override {};
	void IDrawableObject::render(double t, double dt, glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
private:
};