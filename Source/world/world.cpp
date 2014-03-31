#include <typedefs.hpp>

World::World()
{
}

World::~World()
{
	for (auto e : enemies)
	{
		delete e;
	}
}

void World::integrate(double t, double dt)
{
	//UPDATE PHYSICS WORLD
	ship.integrate(t, dt);
	for (auto& enemy : enemies)
	{
		enemy->integrate(t, dt);
	}
}

void World::render(double t, double dt)
{
	glm::mat4 viewMatrix = glm::mat4_cast(camera.rotation);
	viewMatrix = glm::translate(viewMatrix, camera.position);

	ship.render(t, dt, viewMatrix, projectionMatrix);
	for (auto& enemy : enemies)
	{
		enemy->render(t, dt, viewMatrix, projectionMatrix);
	}
}