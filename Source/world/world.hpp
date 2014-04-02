#pragma once

#include <environment/environment.hpp>
#include <player/ship.hpp>
#include <glm.hpp>
#include <stl.hpp>

class World
{
public:
	World();

	Environment environment;
	Ship ship;
	std::list<std::unique_ptr<IEnemy>> enemies;

	glm::mat4 projectionMatrix;

	class Camera : public IPose{} camera;

	void integrate(double t, double dt);
	void render(double t, double dt);
private:
	World(const World&) = delete;
};