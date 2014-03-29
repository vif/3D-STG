#pragma once

#include <assimp/scene.h>

class Model
{
public:
	Model(std::string filename, oglplus::Program* program);
	void draw();
	struct MeshVertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec4 colour;
	};
	struct Material
	{
		glm::vec4 diffuse;
		glm::vec4 specular;
		GLfloat shininess;
	} material;
private:
	std::vector<MeshVertex> _vertices;
	std::vector<GLuint> _indices;
	oglplus::Buffer _faceBuffer;
	oglplus::Buffer _vertexBuffer;
	oglplus::VertexArray _vao;
	const oglplus::Program* _program;
};