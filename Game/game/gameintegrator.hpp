#pragma once

#include "gamestate.hpp"

namespace Game
{
	void Integrate(Game::State& current, double t, double dt);
}