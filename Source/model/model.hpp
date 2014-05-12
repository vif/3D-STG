#pragma once

#include "mesh.hpp"
#include <vector>
#include <memory>
#include <oglplus.hpp>
#include <btBulletDynamicsCommon.h>

namespace Model
{
	class Model
	{
	public:
		Model(std::string filename, oglplus::Program* program);
		void draw(glm::vec4 view_light_direction, glm::mat4 model_matrix, glm::mat4 view_matrix, glm::mat4 projection_matrix);
		btCollisionShape* GetCollisionShape();
		oglplus::Uniform<oglplus::Vec4f> view_light_direction_uniform;
		oglplus::Uniform<oglplus::Mat4f> normal_matrix_uniform;
		oglplus::Uniform<oglplus::Mat4f> model_view_matrix_uniform;
		oglplus::Uniform<oglplus::Mat4f> model_view_projection_matrix_uniform;
	private:
		Model(const Model&) = delete;
		const oglplus::Program* _program;
		std::vector<std::unique_ptr<Mesh>> _meshes;
		std::vector<std::unique_ptr<Material>> _materials;
		std::unique_ptr<btCollisionShape> _shape;
		std::unique_ptr<btTriangleIndexVertexArray> _shape_indexed_vertex_array;
	};
}