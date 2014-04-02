#pragma once

#include <oglplus.hpp>
#include <stl.hpp>

struct ShaderManager
{
	ShaderManager();
	oglplus::Program phong3d;
};

namespace Global
{
	extern std::unique_ptr<ShaderManager> shader_manager;
}