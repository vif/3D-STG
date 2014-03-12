#include <typedefs.hpp>

namespace Shaders
{
	Shaders::Shaders()
	{
		regular = CreateShader("Resources/shaders/regular.vert", "Resources/shaders/regular.frag");
	}

	oglplus::Program CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath)
	{
		oglplus::VertexShader vs(oglplus::GLSLSource::FromFile(vertexShaderFilePath));
		oglplus::FragmentShader fs(oglplus::GLSLSource::FromFile(fragmentShaderFilePath));
		vs.Compile();
		fs.Compile();
		oglplus::Program ret;
		ret.AttachShader(vs);
		ret.AttachShader(fs);
		ret.Link();
		return ret;
	}
}