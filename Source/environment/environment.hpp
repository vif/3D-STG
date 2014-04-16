#pragma once

#include <memory>
#include <object_types/imodelrender.hpp>
#include <object_types/drawable_object.hpp>

class Cylinder : public DrawableObject
{
public:
	Cylinder(Model::Model* model, glm::vec3 init_pos, glm::quat init_orientation) : DrawableObject(init_pos, init_orientation, model){};
private:
	Cylinder(const Cylinder&) = delete;
};

class Environment : public IModelRender
{
public:
	Environment();

	Model::Model cylider;

	std::vector<std::unique_ptr<Cylinder>> cylinders;

	void Render(glm::vec3 camera_position, glm::mat4 view_matrix, glm::mat4 projection_matrix) override;
private:
	Environment(const Environment&) = delete;
};