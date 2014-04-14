#pragma once

#include <object_types/imodelrender.hpp>
#include <object_types/scriptableobject.hpp>

class Cylinder : public SciptableObject
{
	void IUpdatable::Update(double dt) override {};
};

class Environment : public IModelRender
{
public:
	Environment();

	Model::Model cylider;

	std::vector<Cylinder> cylinders;

	void Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
private:

};