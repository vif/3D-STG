#pragma once

#include "scriptable_object.hpp"

class Enemy : public ScriptableObject
{
	public:
		Enemy(ObjectType type, glm::vec3 init_pos, glm::quat init_orientation, Model::Model* model, double weight) : ScriptableObject(type, init_pos, init_orientation, model, weight) {};
		bool alive = true;
	private:
};
