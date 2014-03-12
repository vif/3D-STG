#pragma once

#include <interfaces.hpp>
#include <oglplus.hpp>

class Ship : public IDrawableObject
{
public:
	Ship();
	~Ship() = default;

	oglplus::Program* shader;
	oglplus::Uniform<oglplus::Mat4f> modelView_uniform;
	oglplus::Uniform<oglplus::Mat4f> modelViewProjection_uniform;

	Model model;
	glm::mat4 modelMatrix;

	void IDrawableObject::render(double t, double dt, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
	void IDrawableObject::integrate(double t, double dt) override;
private:
	Ship(const Ship&) = default;
};