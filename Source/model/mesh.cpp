#include "mesh.hpp"

namespace Model
{
	Mesh::Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, Material* material) :
		_program(program),
		_vertices(vertices),
		_indices(indices),
		_material(material),
		diffuse_colour_uniform(*program, "diffuse_colour"),
		ambient_colour_uniform(*program, "ambient_colour"),
		specular_colour_uniform(*program, "specular_colour"),
		specular_shininess_uniform(*program, "specular_shininess")
	{
		//UPLOAD the data onto the GPU
		_vao.Bind();

		_vertexBuffer.Bind(oglplus::BufferOps::Target::Array);
		_vertexBuffer.Data(oglplus::BufferOps::Target::Array, _vertices);

		_faceBuffer.Bind(oglplus::BufferOps::Target::ElementArray);
		_faceBuffer.Data(oglplus::BufferOps::Target::ElementArray, _indices);

		//SETUP attributes
#define make_vaa(name) \
	oglplus::VertexAttribArray name(*program, #name); \
	name.Pointer(sizeof(((Vertex *)0)->name) / sizeof(GLfloat), oglplus::DataType::Float, false, sizeof(Vertex), (const void *) offsetof(Vertex, name)); \
	name.Enable();

		make_vaa(position);
		make_vaa(normal);
		make_vaa(colour);
#undef make_vaa

		oglplus::VertexArray::Unbind();

		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);
		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::ElementArray);
	}

	void Mesh::draw()
	{
		//EXPECTS the program to already be in use

		diffuse_colour_uniform.Set(_material->diffuse_colour);
		ambient_colour_uniform.Set(_material->ambient_colour);
		specular_colour_uniform.Set(_material->specular_colour);
		specular_shininess_uniform.Set(_material->specular_shininess);

		_vao.Bind();

		oglplus::Context::DrawElements(oglplus::PrimitiveType::Triangles, _indices.size(), oglplus::DataType::UnsignedInt);

		oglplus::VertexArray::Unbind(); //unbind the VAOs
	}
}