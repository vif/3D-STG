#include "bullet_debug_drawer.hpp"

btOGLDebugDrawer::btOGLDebugDrawer(oglplus::Program* program) :
_program(program),
model_view_projection_matrix_uniform(*program, "ModelViewProjectionMatrix")
{
	_vao.Bind();
	_vbo.Bind(oglplus::BufferOps::Target::Array);
	//setup the attributes
#define make_vaa(name) \
	oglplus::VertexAttribArray name(*program, #name); \
	name.Pointer(sizeof(((Vertex *)0)->name) / sizeof(GLfloat), oglplus::DataType::Float, false, sizeof(Vertex), (const void *) offsetof(Vertex, name)); \
	name.Enable();

	make_vaa(position);
	make_vaa(colour);
#undef make_vaa

	oglplus::VertexArray::Unbind();
	oglplus::VertexArray::Unbind();
}

void btOGLDebugDrawer::drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
{
	Vertex vertex_from;
	Vertex vertex_to;

	vertex_from.position = glm::vec4(from.x(), from.y(), from.z(), 1);
	vertex_from.colour = glm::vec4(1, 0, 0, 1);
	//vertex_from.colour = glm::vec4(color.x(), color.y(), color.z(), 1);

	vertex_to.position = glm::vec4(to.x(), to.y(), to.z(), 1);
	vertex_to.colour = glm::vec4(1, 0, 0, 1);
	//vertex_to.colour = glm::vec4(color.x(), color.y(), color.z(), 1);

	_lines.push_back(vertex_from);
	_lines.push_back(vertex_to);
}

void btOGLDebugDrawer::drawAndClear(glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	_program->Use();

	//model projection is identity so we can ignore it
	model_view_projection_matrix_uniform.Set(projection_matrix * view_matrix);

	//do the draw call
	_vao.Bind();
	_vbo.Bind(oglplus::BufferOps::Target::Array);

	_vbo.Data(oglplus::BufferOps::Target::Array, _lines);
	oglplus::Context::DrawArrays(oglplus::PrimitiveType::Lines, 0, _lines.size());

	oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);
	oglplus::VertexArray::Unbind();

	oglplus::Program::UseNone();

	_lines.clear();
}