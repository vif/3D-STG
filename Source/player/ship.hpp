#pragma once

#include <object_types/scriptablephysicsobject.hpp>

class Ship : public ScriptablePhysicsObject
{
public:
	Ship();

	Model::Model model;

	const float weight = 100;

	void Update(double dt, World* world) override;
private:
	Ship(const Ship&) = delete;
};