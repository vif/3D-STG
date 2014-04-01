#include <typedefs.hpp>

World::World()
{
}

void World::integrate(double t, double dt)
{
	//UPDATE PHYSICS WORLD

	ship.integrate(t, dt);

	for (auto& enemy : enemies)
	{
		enemy->integrate(t, dt);
	}

	//set camera to be be 10 units behind, and 5 units above the ship
	camera.position = ship.position + glm::rotate(ship.rotation, glm::vec3(-10, 5, 0));
	camera.rotation = ship.rotation;
}

void World::render(double t, double dt)
{
	auto viewMatrix = glm::lookAt(camera.position, glm::rotate(camera.rotation, glm::vec3(1, 0, 0)), glm::rotate(camera.rotation, glm::vec3(0, 1, 0)));

	ship.render(t, dt, camera.position, viewMatrix, projectionMatrix);
	for (auto& enemy : enemies)
	{
		enemy->render(t, dt, camera.position, viewMatrix, projectionMatrix);
	}
}