#pragma once

#include <oglplus.hpp>

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