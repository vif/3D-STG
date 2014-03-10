#pragma once

class Enemy
{
public:
	virtual void integrate(double t, double dt) = 0;
private:
};
