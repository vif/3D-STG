#pragma once

#include <interfaces.hpp>
#include <oglplus.hpp>

class Ship : public IDrawableObject
{
public:
	Ship();
	~Ship() = default;

	Model::Model model;
	glm::vec3 position;
	glm::quat rotation;

	void IDrawableObject::render(double t, double dt, glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
	void IDrawableObject::integrate(double t, double dt) override;
private:
	Ship(const Ship&) = delete;
};