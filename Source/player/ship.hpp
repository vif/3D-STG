#pragma once

#include <object_types/scriptablephysicsobject.hpp>
#include <oglplus.hpp>
#include <model/model.hpp>

class Ship : public ScriptablePhysicsObject
{
public:
	Ship();
	~Ship() = default;

	Model::Model model;

	const float weight = 100;

	void Update(double dt, World* world) override;
private:
	Ship(const Ship&) = delete;
};