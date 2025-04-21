#include "player.h"

void C_Player::Init()
{
	m_pPos = { -640+192,360-192 };
}

void C_Player::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pPos.x -= 10;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pPos.x += 10;

	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_pPos.y -= 10;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_pPos.y += 10;
	}

}

void C_Player::Draw()
{
	m_scaleMat = Math::Matrix::CreateScale(1, 1, 0);
	m_transMat = Math::Matrix::CreateTranslation(m_pPos.x, m_pPos.y, 0);
	matrix = m_scaleMat * m_transMat;
	SHADER.m_spriteShader.SetMatrix(matrix);
	SHADER.m_spriteShader.DrawTex(m_playerTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);
}
