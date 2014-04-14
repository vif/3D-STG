#pragma once

class World;

class InputManager
{
public:
	InputManager(World* world) : _world(world){}
	void keyboard(int key, int action, int mods);
	void mouse(double dx, double dy);
private:
	World* _world;
};