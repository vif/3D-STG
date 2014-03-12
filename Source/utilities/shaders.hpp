#pragma once

#include <oglplus.hpp>
#include <memory>

namespace Shaders
{
	struct Shaders
	{
		Shaders();
		oglplus::Program regular;
	};

	extern std::unique_ptr<Shaders> SHADERS;

	oglplus::Program CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
}