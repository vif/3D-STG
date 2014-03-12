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
}

void World::render(double t, double dt)
{
	ship.render(t, dt, viewMatrix, projectionMatrix);
	for (auto& enemy : enemies)
	{
		enemy->render(t, dt, viewMatrix, projectionMatrix);
	}
}