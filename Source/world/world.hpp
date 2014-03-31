#pragma once

#include <interfaces.hpp>
#include <player/ship.hpp>
#include <oglplus.hpp>
#include <glm/glm.hpp>
#include <memory>
#include <list>

class World
{
public:
	World();

	Ship ship;
	std::list<std::unique_ptr<IEnemy>> enemies;

	glm::mat4 projectionMatrix;

	struct Camera
	{
		glm::vec3 position;
		glm::quat rotation;
	} camera;

	void integrate(double t, double dt);
	void render(double t, double dt);
private:
	World(const World&) = delete;
};