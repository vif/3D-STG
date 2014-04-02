#pragma once

#include <oglplus.hpp>

struct ShaderManager
{
	ShaderManager();
	oglplus::Program phong3d;
};

namespace Global
{
	extern ShaderManager* shader_manager;
}