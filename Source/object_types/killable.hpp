#pragma once

class Killable
{
public:
	Killable::Killable(double max_health) : max_health(max_health), _current_health(max_health){}
	void ReceiveHealthOffset(double h);
	void SetHealth(double h);
	double GetHealth();
	const double max_health;
	bool alive = true;
private:
	double _current_health;
	void _normalize_health();
};