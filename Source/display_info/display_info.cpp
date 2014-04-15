#include "display_info.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>

void DisplayInfo::SetScreenSize(int width, int height)
{
	_screen_width = width;
	_screen_height = height;

	auto aspect_ratio = glm::golden_ratio<double>();
	_projection_matrix = glm::infinitePerspective<double>(glm::radians(45.0f), aspect_ratio, 0.1);

	//TODO: setup viewport
}

int DisplayInfo::getScreenHeight()
{
	return _screen_height;
}

int DisplayInfo::getScreenWidth()
{
	return _screen_width;
}

glm::mat4 DisplayInfo::getProjectionMatrix()
{
	return _projection_matrix;
}

glm::mat3 DisplayInfo::getViewPort()
{
	return _view_port;
}
