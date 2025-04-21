#pragma once
#include"player.h"
#include"maze.h"

class C_Hit
{
private:
	C_Maze m_maze;
	C_Player m_player;

	Math::Vector2 m_pos;

public:
	void Init();

	Math::Vector2 Block(Math::Vector2 pos, Math::Vector2 radius, Math::Vector2 move);


};
