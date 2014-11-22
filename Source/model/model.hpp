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
		btCollisionShape* GetCollisionShape();
		const oglplus::Program* program;
		void draw();
		void draw_instanced(unsigned int num);
		std::vector<std::unique_ptr<Mesh>> meshes;
	protected:
	private:
		std::vector<std::unique_ptr<Material>> _materials;
		std::unique_ptr<btCollisionShape> _shape;
		std::unique_ptr<btTriangleIndexVertexArray> _shape_indexed_vertex_array;
		Model(const Model&) = delete;
	};
}