#include "cylinder_grid.hpp"
#include <glm/gtc/random.hpp>
#include <glm/ext.hpp>
#include <utilities/ShaderManager/shadermanager.hpp>


CylinderGrid::CylinderGrid() :
_program(CreateShader(oglplus::GLSLSource::FromFile("Resources/shaders/cylinder_grid.vert"), oglplus::GLSLSource::FromFile("Resources/shaders/phong.frag"))),
_view_light_direction_uniform(_program, "ViewLightDirection"), 
_view_matrix_uniform( _program, "ViewMatrix"),
_view_projection_matrix_uniform(_program, "ViewProjectionMatrix")
{
	_model = std::make_unique<Model::Model>("Resources/models/environment/cylinders.obj", &_program);

	std::vector<float> cylinders;
	cylinders.resize(_num * 16);

	for (auto i = 0; i < _num; ++i)
	{
		auto pos = glm::ballRand<float>(_spread_distance);
		auto orientation = glm::quat(glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f), glm::linearRand(0.0f, 1.0f));
		auto c = glm::translate(pos) * glm::mat4_cast(orientation);
		memcpy(&cylinders[i * 16], glm::value_ptr(c), sizeof(float) * 16);
	}

	_line_positions.Bind(oglplus::BufferOps::Target::Array);
	_line_positions.Data(oglplus::BufferOps::Target::Array, cylinders);
	oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);

	for (auto& mesh : _model->meshes)
	{
		mesh->bindVAO();

		_line_positions.Bind(oglplus::BufferOps::Target::Array);
		
		GLint model_matrix_vaa = (GLint)oglplus::VertexAttribArray::GetLocation(_program, "model_matrix");

		for (auto i = 0; i < 4; ++i)
		{
			oglplus::VertexAttribArray vaa(oglplus::VertexAttribSlot(model_matrix_vaa + i));
			vaa.Pointer(4, oglplus::DataType::Float, false, sizeof(GLfloat) * 16, (void*)(4 * i * sizeof(float)));
			vaa.Divisor(1);
			vaa.Enable();
		}

		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);

		mesh->unbindVAO();
	}
}

void CylinderGrid::Render(const glm::vec4& view_light_direction, const glm::mat4& view_matrix, const glm::mat4& projection_matrix)
{
	auto view_projection_matrix = projection_matrix * view_matrix;

	_program.Use();

	_view_matrix_uniform.Set(view_matrix);
	_view_projection_matrix_uniform.Set(view_projection_matrix);
	_view_light_direction_uniform.Set(view_light_direction);

	_model->draw_instanced(_num);

	_program.UseNone();
}

