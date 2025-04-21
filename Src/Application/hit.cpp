#include "hit.h"

void C_Hit::Init()
{

}

Math::Vector2 C_Hit::Block(Math::Vector2 pos, Math::Vector2 radius, Math::Vector2 move)
{
	m_pos = pos;
	const float playerLeft = pos.x - radius.x;
	const float playerRight = pos.x + radius.x;
	const float playerBottom = pos.y - radius.y;
	const float playerTop = pos.y + radius.y;

	//ñ¢óàç¿ïW
	const float nextLeft = playerLeft + move.x;
	const float nextRight = playerRight + move.x;
	const float nextBottom = playerBottom + move.y;
	const float nextTop = playerTop + move.y;
	for (int i = 0; i < m_maze.GetHEIGHT(); i++)
	{
		for (int j = 0; j < m_maze.GetWIDTH(); j++)
		{
			const float chipLeft = m_maze.GetPos(i,j).x - m_maze.GetRadius();
			const float chipRight = m_maze.GetPos(i, j).x + m_maze.GetRadius();
			const float chipBottom = m_maze.GetPos(i, j).y - m_maze.GetRadius();
			const float chipTop = m_maze.GetPos(i, j).y + m_maze.GetRadius();
			if (playerRight > chipLeft && playerLeft < chipRight)
			{
				if (nextBottom < chipTop && nextTop > chipTop)
				{
					pos.y = 0;
					m_pos.y = chipTop + radius.y;
				}
				else if (nextTop > chipBottom && nextBottom < chipBottom)
				{
					pos.y = 0;
					m_pos.y = chipBottom - radius.y;
				}
			}

			if (playerTop > chipBottom && playerBottom < chipTop)
			{
				if (nextLeft < chipRight && nextRight > chipRight)
				{
					pos.x = 0;
					m_pos.x = chipRight + radius.x;
				}
				else if (nextRight > chipLeft && nextLeft < chipLeft)
				{
					pos.x = 0;
					m_pos.x = chipLeft - radius.x;
				}
			}
		}
	}
	
	return m_pos;
}
