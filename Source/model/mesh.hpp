#pragma once

#include <oglplus.hpp>
#include <glm/glm.hpp>

namespace Model
{
	struct Material
	{
		glm::fvec3 diffuse_colour = { 1, 1, 1 };
		glm::fvec3 ambient_colour = { 0.1, 0.1, 0.1 };
		glm::fvec3 specular_colour = { 1, 1, 1 };
		GLfloat specular_shininess = 1;
	};

	struct Vertex
	{
		glm::fvec4 position;
		glm::fvec4 normal;
		glm::fvec4 colour = glm::vec4(1, 1, 1, 1);
	};

	class Mesh
	{
	public:
		Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLint>& indices, Material* material);
		void draw();
		oglplus::Uniform<oglplus::Vec3f> diffuse_colour_uniform;
		oglplus::Uniform<oglplus::Vec3f> ambient_colour_uniform;
		oglplus::Uniform<oglplus::Vec3f> specular_colour_uniform;
		oglplus::Uniform<GLfloat>		 specular_shininess_uniform;	
		std::vector<GLint> indices;
		std::vector<Vertex> vertices;
	private:
		Mesh(const Mesh&) = delete;
		const oglplus::Program* _program;
		oglplus::VertexArray _vao;
		oglplus::Buffer _faceBuffer;
		oglplus::Buffer _vertexBuffer;
		Material* _material;
	};
}