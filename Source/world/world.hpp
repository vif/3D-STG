#pragma once

#include <interfaces.hpp>
#include <player/ship.hpp>
#include <oglplus.hpp>
#include <memory>
#include <list>

class World
{
public:
	World();

	Ship ship;
	std::list<std::shared_ptr<IEnemy>> enemies;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	void integrate(double t, double dt);
	void render(double t, double dt);
private:
};