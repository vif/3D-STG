#include "shadermanager.hpp"

oglplus::Program CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath, std::string geomentryShaderFilePath = "")
{
	oglplus::Program ret;

	oglplus::VertexShader vs(oglplus::GLSLSource::FromFile(vertexShaderFilePath));
	vs.Compile();
	ret.AttachShader(vs);
	fputs(vs.GetInfoLog().c_str(), stderr);

	if (geomentryShaderFilePath != "")
	{
		oglplus::GeometryShader gm(oglplus::GLSLSource::FromFile(geomentryShaderFilePath));
		gm.Compile();
		ret.AttachShader(gm);
		fputs(gm.GetInfoLog().c_str(), stderr);
	}

	oglplus::FragmentShader fs(oglplus::GLSLSource::FromFile(fragmentShaderFilePath));
	fs.Compile();
	ret.AttachShader(fs);
	fputs(fs.GetInfoLog().c_str(), stderr);

	ret.Link();

	fputs(ret.GetInfoLog().c_str(), stderr);

	assert(ret.IsLinked());
	assert(ret.IsValid());

	return ret;
}

ShaderManager::ShaderManager()
{
	phong3d = CreateShader("Resources/shaders/3d.vert", "Resources/shaders/phong.frag");
}