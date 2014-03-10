#pragma once

#include <list>
#include <memory>
#include <enemies/enemy.hpp>

namespace Game
{
	class State
	{
	public:
		State() = default;
		~State() = default;
		State(const Game::State &);
		std::list<std::unique_ptr<Enemy>> enemies;
		State& operator=(const State& rhs);
		State operator*(const double& scale);
		State operator+(const State& rhs);
	private:
	};
}