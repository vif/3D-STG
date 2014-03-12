#pragma once

#include <assimp/scene.h>

class Model
{
public:
	Model(std::string filename);
	void draw(oglplus::Program* program);
	struct MeshVertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec4 colour;
		glm::vec3 UV;
	};
private:
	std::vector<MeshVertex> _vertices;
	std::vector<glm::uint> _indices;
	oglplus::Buffer _faceBuffer;
	oglplus::Buffer _vertexBuffer;
	oglplus::VertexArray _vao;
};