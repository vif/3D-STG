#include <typedefs.hpp>

Ship::Ship() :
shader(&Shaders::shared_shaders->regular),
modelViewMatrix_uniform(*shader, "ModelViewMatrix"),
normalMatrix_uniform(*shader, "NormalMatrix"),
modelViewProjectionMatrix_uniform(*shader, "ModelViewProjectionMatrix"),
materialDiffuse_uniform(*shader, "materialDiffuse"),
materialSpecular_uniform(*shader, "materialSpecular"),
materialShininess_uniform(*shader, "materialShininess"),
model("Resources/models/player/ship.obj", shader)
{
}

void Ship::integrate(double t, double dt)
{
}

void Ship::render(double t, double dt, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	shader->Use();

	auto modelMatrix = glm::mat4_cast(rotation);
	modelMatrix = glm::translate(modelMatrix, position);

	viewMatrix = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	auto modelViewMatrix = viewMatrix * modelMatrix;
	auto normalMatrix = glm::transpose(glm::inverse(modelViewMatrix));
	auto modelViewProjectionMatrix = projectionMatrix * modelViewMatrix;

	modelViewMatrix_uniform.Set(modelViewMatrix);
	normalMatrix_uniform.Set(normalMatrix);
	modelViewProjectionMatrix_uniform.Set(modelViewProjectionMatrix);

	materialDiffuse_uniform.Set(model.material.diffuse);
	materialSpecular_uniform.Set(model.material.specular);
	//materialShininess_uniform.Set(model.material.shininess);

	shader->UseNone();

	model.draw();
}