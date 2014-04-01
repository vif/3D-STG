#pragma once


namespace Model
{
	struct Material
	{
		glm::vec3 diffuse_colour = { 1, 1, 1 };
		glm::vec3 ambient_colour = { 0.1, 0.1, 0.1 };
		glm::vec3 specular_colour = { 1, 1, 1 };
		GLfloat specular_shininess = 1;
	};

	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec3 colour = glm::vec3(1, 1, 1);
	};

	class Mesh
	{
	public:
		Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, Material* material);
		void draw();
		oglplus::Uniform<oglplus::Vec3f> diffuse_colour_uniform;
		oglplus::Uniform<oglplus::Vec3f> ambient_colour_uniform;
		oglplus::Uniform<oglplus::Vec3f> specular_colour_uniform;
		oglplus::Uniform<GLfloat>		 specular_shininess_uniform;
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
}