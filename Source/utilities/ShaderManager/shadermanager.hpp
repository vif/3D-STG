#pragma once

#include <oglplus.hpp>

oglplus::Program CreateShader(oglplus::GLSLSource vertexShaderSource, oglplus::GLSLSource fragmentShaderSource);

struct ShaderManager
{
	ShaderManager();
	oglplus::Program phong3d;
	oglplus::Program simple;
};

namespace Global
{
	extern ShaderManager* shader_manager;
}