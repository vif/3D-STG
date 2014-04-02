#pragma once

#include <glm.hpp>

class IPose
{
public:
	glm::vec3 position;
	glm::quat orientation = { 1, 0, 0, 0 };
private:
};