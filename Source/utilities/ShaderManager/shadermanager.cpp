#include "shadermanager.hpp"

oglplus::Program CreateShader(oglplus::GLSLSource vertexShaderSource, oglplus::GLSLSource fragmentShaderSource)
{
	oglplus::Program ret;

	oglplus::VertexShader vs;
	try
	{
		vs.Source(vertexShaderSource).Compile();
	}
	catch (...)
	{
		fputs(vs.GetInfoLog().c_str(), stderr);
	}
	ret.AttachShader(vs);


	oglplus::FragmentShader fs;
	try
	{
		fs.Source(fragmentShaderSource).Compile();
	}
	catch (...)
	{
		fputs(fs.GetInfoLog().c_str(), stderr);
	}

	ret.AttachShader(fs);

	try
	{
		ret.Link();
	}
	catch (...)
	{
		fputs(ret.GetInfoLog().c_str(), stderr);
	}

	if (!ret.IsLinked() || !ret.IsValid())
	{
		exit(1);
	}
	return ret;
}

ShaderManager::ShaderManager()
{
	simple = CreateShader(oglplus::GLSLSource::FromFile("Resources/shaders/3d.vert"), oglplus::GLSLSource::FromFile("Resources/shaders/simple.frag"));
	phong3d = CreateShader(oglplus::GLSLSource::FromFile("Resources/shaders/3d.vert"), oglplus::GLSLSource::FromFile("Resources/shaders/phong.frag"));
}