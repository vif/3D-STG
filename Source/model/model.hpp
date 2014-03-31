#pragma once

#include <assimp/scene.h>
#include <oglplus.hpp>
#include <vector>
#include <memory>

namespace Model
{
	struct Material
	{
		glm::vec3 diffuse_colour;
		glm::vec3 ambient_colour;
		glm::vec3 specular_colour;
		GLfloat shininess;
		oglplus::Texture texture;
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
		Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, Material* material);
		void draw();
	private:
		Mesh(const Mesh&) = delete;
		const oglplus::Program* _program;
		std::vector<Vertex> _vertices;
		std::vector<GLuint> _indices;
		oglplus::Buffer _faceBuffer;
		oglplus::Buffer _vertexBuffer;
		oglplus::VertexArray _vao;
		Material* _material;
	};

	class Model
	{
	public:
		Model(std::string filename, oglplus::Program* program);
		~Model();
		void draw();
	private:
		Model(const Model&) = delete;
		const oglplus::Program* _program;
		std::vector<Mesh*> _meshes;
		std::vector<Material*> _materials;
	};
}