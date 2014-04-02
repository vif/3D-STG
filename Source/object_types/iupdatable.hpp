#pragma once

class World;

class IUpdatable
{
public:
	virtual void Update(double dt, World* world) = 0;
private:
};