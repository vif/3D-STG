#pragma once

#include <glm/glm.hpp>

class DisplayInfo
{
public:
	void SetScreenSize(int width, int height);
	int getScreenHeight();
	int getScreenWidth();
	glm::mat4 getProjectionMatrix();
	glm::mat3 getViewPort();
private:
	int _screen_height;
	int _screen_width;
	glm::mat4 _projection_matrix;
	glm::mat3 _view_port;
};