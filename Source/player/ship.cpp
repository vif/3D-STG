#include <typedefs.hpp>

Ship::Ship() :
model("Resources/models/player/ship.obj"),
shader(&Shaders::SHADERS->regular),
modelView_uniform(*shader, "ModelViewMatrix"),
modelViewProjection_uniform(*shader, "ModelViewProjectionMatrix")
{
}

void Ship::integrate(double t, double dt)
{

}

void Ship::render(double t, double dt, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	shader->Use();

	modelView_uniform.Set(modelMatrix * viewMatrix);
	modelViewProjection_uniform.Set(modelMatrix * viewMatrix * projectionMatrix);

	shader->UseNone();

	model.draw(shader);
}