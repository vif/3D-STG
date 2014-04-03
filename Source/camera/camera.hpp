#pragma once

#include <object_types/scriptableobject.hpp>

class Camera : public SciptableObject
{
public:
	void Update(double dt, World* world) override;
	bool attachedToShip = true;
private:
};