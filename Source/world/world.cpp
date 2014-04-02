#include "world.hpp"

World::World()
{
}

void World::integrate(double t, double dt)
{
	//UPDATE PHYSICS WORLD

	environment.integrate(t, dt);

	ship.integrate(t, dt);

	for (auto& enemy : enemies)
	{
		enemy->integrate(t, dt);
	}

	//set camera to be behind and above the ship
	camera.position = ship.position + glm::rotate(ship.orientation, glm::vec3(-21, 8, 0));
	camera.orientation = ship.orientation;
}

void World::render(double t, double dt)
{
	auto camera_dir = camera.position +  glm::rotate(camera.orientation, glm::vec3(1, 0, 0));
	auto camera_up = glm::rotate(camera.orientation, glm::vec3(0, 1, 0));
	auto viewMatrix = glm::lookAt(camera.position, camera_dir, camera_up);

	environment.render(t, dt, camera.position, viewMatrix, projectionMatrix);
	ship.render(t, dt, camera.position, viewMatrix, projectionMatrix);
	for (auto& enemy : enemies)
	{
		enemy->render(t, dt, camera.position, viewMatrix, projectionMatrix);
	}
}