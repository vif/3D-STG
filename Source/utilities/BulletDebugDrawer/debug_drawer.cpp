#include "debug_drawer.hpp"

btOGLDebugDrawer::btOGLDebugDrawer(oglplus::Program* program) :
_program(program),
modelViewProjectionMatrix_uniform(*program, "ModelViewProjectionMatrix")
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

void btOGLDebugDrawer::drawAndClear(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	_program->Use();

	//model projection is identity so we can ignore it
	modelViewProjectionMatrix_uniform.Set(projectionMatrix * viewMatrix);

	//copy the list into a vector so we can draw it
	std::vector<Vertex> vl;
	vl.reserve(_lines.size());
	//WARNING: uses the move iterator so origin list no longer valid
	vl.insert(vl.end(), std::make_move_iterator(std::begin(_lines)), std::make_move_iterator(std::end(_lines)));
	//resets all the points we accumulated
	_lines.clear();


	//do the draw call
	_vao.Bind();
	_vbo.Bind(oglplus::BufferOps::Target::Array);

	_vbo.Data(oglplus::BufferOps::Target::Array, vl);
	oglplus::Context::DrawArrays(oglplus::PrimitiveType::Lines, 0, vl.size());

	oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);
	oglplus::VertexArray::Unbind();

	oglplus::Program::UseNone();
}