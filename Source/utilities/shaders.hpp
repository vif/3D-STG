#pragma once

#include <oglplus.hpp>

namespace Shaders
{
	struct SharedShaders
	{
		SharedShaders();
		oglplus::Program regular;
	};

	extern SharedShaders* shared_shaders;

	oglplus::Program CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
}