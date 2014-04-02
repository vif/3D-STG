#pragma once

#include <object_types/scriptableobject.hpp>

class Cylinder : public SciptableObject
{
	void SciptableObject::Update(double dt, World* world) override {};
};

class Environment : public SciptableObject
{
public:
	Environment();

	Model::Model cylider;

	std::vector<Cylinder> cylinders;

	void Update(double dt, World* world) override {};
	void Render(glm::vec3 camera_position, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) override;
private:
};