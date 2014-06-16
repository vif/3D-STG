#pragma once

#include <btBulletDynamicsCommon.h>

class ICollidable
{
public:
	virtual void Collision(ICollidable*) = 0;
};