#pragma once

#include <interfaces.hpp>
#include <oglplus.hpp>

class Ship : public IDrawableObject
{
public:
	Ship();
	~Ship() = default;

	oglplus::Program* shader;
	oglplus::Uniform<oglplus::Mat4f> modelViewMatrix_uniform;
	oglplus::Uniform<oglplus::Mat4f> normalMatrix_uniform;
	oglplus::Uniform<oglplus::Mat4f> modelViewProjectionMatrix_uniform;
	oglplus::Uniform<oglplus::Vec4f> materialDiffuse_uniform;
	oglplus::Uniform<oglplus::Vec4f> materialSpecular_uniform;
	oglplus::Uniform<GLfloat> materialShininess_uniform;

	Model model;
	glm::vec3 position;
	glm::quat rotation;

	void IDrawableObject::render(double t, double dt, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
	void IDrawableObject::integrate(double t, double dt) override;
private:
	Ship(const Ship&) = default;
};