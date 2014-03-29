#pragma once

#include <oglplus.hpp>
#include <memory>

namespace Shaders
{
	struct SharedShaders
	{
		SharedShaders();
		oglplus::Program regular;
	};

	extern std::unique_ptr<SharedShaders> shared_shaders;

	oglplus::Program CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);
}