#pragma once

#include <assimp/scene.h>
#include <oglplus.hpp>
#include <vector>

namespace Model
{
	struct Material
	{
		glm::vec4 diffuse;
		glm::vec4 specular;
		GLfloat shininess;
	};

	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec4 colour;
	};

	class Mesh
	{
	public:
		Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
		void draw();
	private:
		const oglplus::Program* _program;
		std::vector<Vertex> _vertices;
		std::vector<GLuint> _indices;
		oglplus::Buffer _faceBuffer;
		oglplus::Buffer _vertexBuffer;
		oglplus::VertexArray _vao;
	};

	class Model
	{
	public:
		Model(std::string filename, oglplus::Program* program);
		~Model();
		void draw();
	private:
		const oglplus::Program* _program;
		std::vector<Mesh*> _meshes;
	};
}