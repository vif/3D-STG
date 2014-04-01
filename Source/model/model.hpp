#pragma once

#include <assimp/scene.h>
#include <oglplus.hpp>
#include <vector>
#include <memory>
#include "mesh.hpp"

namespace Model
{
	class Model
	{
	public:
		Model(std::string filename, oglplus::Program* program);
		void draw(glm::vec3 camera_position, glm::mat4 modelMatrix, glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
		oglplus::Uniform<oglplus::Vec3f> camera_position_uniform;
		oglplus::Uniform<oglplus::Mat4f> normalMatrix_uniform;
		oglplus::Uniform<oglplus::Mat4f> modelViewProjectionMatrix_uniform;
	private:
		Model(const Model&) = delete;
		const oglplus::Program* _program;
		std::vector<std::unique_ptr<Mesh>> _meshes;
		std::vector<std::unique_ptr<Material>> _materials;
	};
}