#include "gamestate.hpp"

Game::State::State(const Game::State &)
{
}

Game::State& Game::State::operator=(const Game::State& rhs)
{
	return *this;
}

Game::State Game::State::operator*(const double& scale)
{
	return Game::State();
}

Game::State Game::State::operator+(const Game::State& rhs)
{
	return Game::State();
}