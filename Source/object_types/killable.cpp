#include "killable.hpp"

void Killable::ReceiveHealthOffset(double h)
{
	_current_health += h;
	_normalize_health();
}

void Killable::SetHealth(double h)
{
	_current_health = h;
	_normalize_health();
}

double Killable::GetHealth()
{
	return _current_health;
}

void Killable::_normalize_health()
{
	if (_current_health <= 0)
	{
		alive = false;
		_current_health = 0;
	}

	if (_current_health > max_health)
	{
		_current_health = max_health;
	}
}


