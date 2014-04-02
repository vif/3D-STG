#pragma once

#include <interfaces.hpp>
#include <oglplus.hpp>
#include <model/model.hpp>

class Ship : public IDrawableObject, public IPose
{
public:
	Ship();
	~Ship() = default;

	Model::Model model;

	void IDrawableObject::render(double t, double dt, glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
	void IDrawableObject::integrate(double t, double dt) override;
private:
	Ship(const Ship&) = delete;
};