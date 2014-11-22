#include "mesh.hpp"

namespace Model
{
	Mesh::Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLint>& indices, Material* material) :
		_program(program),
		vertices(vertices),
		indices(indices),
		_material(material),
		diffuse_colour_uniform(*program, "diffuse_colour"),
		ambient_colour_uniform(*program, "ambient_colour"),
		specular_colour_uniform(*program, "specular_colour"),
		specular_shininess_uniform(*program, "specular_shininess")
	{
		//UPLOAD the data onto the GPU
		_vao.Bind();

		face_buffer.Bind(oglplus::BufferOps::Target::ElementArray);
		face_buffer.Data(oglplus::BufferOps::Target::ElementArray, indices);

		vertex_buffer.Bind(oglplus::BufferOps::Target::Array);
		vertex_buffer.Data(oglplus::BufferOps::Target::Array, vertices);
		//SETUP attributes
#define make_vaa(name) \
	oglplus::VertexAttribArray name(*_program, #name); \
	name.Pointer(sizeof(((Vertex *)0)->name) / sizeof(GLfloat), oglplus::DataType::Float, false, sizeof(Vertex), (const void *) offsetof(Vertex, name)); \
	name.Enable();

		make_vaa(position);
		make_vaa(normal);
		make_vaa(colour);
		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);
#undef make_vaa

		oglplus::VertexArray::Unbind();

		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::ElementArray);
	}

	void Mesh::_bind_uniforms()
	{
		diffuse_colour_uniform.Set(_material->diffuse_colour);
		ambient_colour_uniform.Set(_material->ambient_colour);
		specular_colour_uniform.Set(_material->specular_colour);
		specular_shininess_uniform.Set(_material->specular_shininess);
	}

	void Mesh::draw()
	{
		//EXPECTS the program to already be in use

		_bind_uniforms();

		_vao.Bind();

		oglplus::Context::DrawElements(oglplus::PrimitiveType::Triangles, indices.size(), oglplus::DataType::UnsignedInt);

		oglplus::VertexArray::Unbind(); //unbind the VAOs
	}

	void Mesh::draw_instanced(unsigned int num)
	{
		//EXPECTS the program to already be in use

		_bind_uniforms();

		_vao.Bind();

		oglplus::Context::DrawElementsInstanced(oglplus::PrimitiveType::Triangles, indices.size(), oglplus::DataType::UnsignedInt, num);

		oglplus::VertexArray::Unbind(); //unbind the VAOs
	}

	void Mesh::bindVAO()
	{
		_vao.Bind();
	}

	void Mesh::unbindVAO()
	{
		_vao.Unbind();
	}
}