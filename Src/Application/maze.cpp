#include "maze.h"

void C_Maze::Init()
{
	//����������
	srand(time(0));

	keyFlg = false;

	dir = Direction::Up;

	player = { 0,0 };
}

void C_Maze::Update()
{
	CreateMaze();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (m_bPos[0][0].x < -640)
		{
			player.x += 10;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{

		if (m_bPos[MAZE_HEIGHT - 1][MAZE_WIDTH - 1].x > 640)
		{
			player.x -= 10;
		}

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (m_bPos[MAZE_HEIGHT - 1][MAZE_WIDTH - 1].y < -360)
		{
			player.y += 10;
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (m_bPos[0][0].y > 360)
		{
			player.y -= 10;
		}
	}
}

void C_Maze::Draw()
{
	for (int w = 0; w < MAZE_WIDTH; w++)
	{
		for (int h = 0; h < MAZE_HEIGHT; h++)
		{
			if (mazeFlg[h][w] == 1)
			{
				if (w == 0)
				{
					m_bPos[h][w] = { -640 + 64 * w * 3 + player.x, 360 - 64 * h * 3 + player.y };
				}
				else
				{
					m_bPos[h][w] = { -640 + 64 * w * 3 + player.x, 360 - 64 * h * 3 + player.y };
				}
				
				m_scaleMat = Math::Matrix::CreateScale(3,3, 0);
				m_transMat = Math::Matrix::CreateTranslation(-640 + 64 * w * 3 + player.x, 360 - 64 * h * 3 + player.y, 0);
				matrix = m_scaleMat * m_transMat;
				SHADER.m_spriteShader.SetMatrix(matrix);
				SHADER.m_spriteShader.DrawTex(m_blockTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);
			}
		}
	}
}

void C_Maze::InitMaze()
{
	//�O�g�u���b�N
	for (int h = 0; h < MAZE_HEIGHT; h++)
	{
		for (int w = 0; w < MAZE_WIDTH; w++)
		{
			mazeFlg[h][w] = 1;
		}
	}
	//�X�^�[�g�n�_
	x = 1;
	y = 1;
	mazeFlg[y][x] = 0;

	//�@��邩�t���O
	digFlg = true;

	//�����̃��Z�b�g
	for (int i = 0; i < SAVE_MAX; i++)
	{
		save[i] = Direction::None;
	}
	digCnt = 0;
}

void C_Maze::CreateMaze()
{
	//=====================================================
	//���H���@��i�߂鏈��
	//=====================================================
	dir = (Direction)(rand() % Direction::Kind);
	switch (dir)
	{
	case	Direction::Up:      //��
		if (y - 2 >= 1 && mazeFlg[y - 2][x] == 1)
		{
			mazeFlg[y - 1][x] = 0;
			mazeFlg[y - 2][x] = 0;
			y -= 2;
			//�@���������̋L�^
			save[digCnt] = Direction::Up;
			digCnt++;
		}
		break;
	case	Direction::Down:    //��
		if (y + 2 < MAZE_HEIGHT - 1 && mazeFlg[y + 2][x] == 1)
		{
			mazeFlg[y + 1][x] = 0;
			mazeFlg[y + 2][x] = 0;
			y += 2;
			//�@���������̋L�^
			save[digCnt] = Direction::Down;
			digCnt++;
		}
		break;
	case	Direction::Left:    //��
		if (x - 2 >= 1 && mazeFlg[y][x - 2] == 1)
		{
			mazeFlg[y][x - 1] = 0;
			mazeFlg[y][x - 2] = 0;
			x -= 2;
			//�@���������̋L�^
			save[digCnt] = Direction::Left;
			digCnt++;
		}
		break;
	case	Direction::Right:   //�E
		if (x + 2 < MAZE_WIDTH - 1 && mazeFlg[y][x + 2] == 1)
		{

			mazeFlg[y][x + 1] = 0;
			mazeFlg[y][x + 2] = 0;
			x += 2;
			//�@���������̋L�^
			save[digCnt] = Direction::Right;
			digCnt++;

		}
		break;
	}

	//=====================================================
	//���̃t���[���łǂ����܂��@���ꍇ��true�ɂ���
	//=====================================================
	digFlg = false;
	if (y - 2 >= 1 && mazeFlg[y - 2][x] == 1)
	{
		digFlg = true;
	}
	else if (y + 2 < MAZE_HEIGHT - 1 && mazeFlg[y + 2][x] == 1)
	{
		digFlg = true;
	}
	else if (x - 2 >= 1 && mazeFlg[y][x - 2] == 1)
	{
		digFlg = true;
	}
	else if (x + 2 < MAZE_WIDTH - 1 && mazeFlg[y][x + 2] == 1)
	{
		digFlg = true;
	}

	//
	if (!digFlg)
	{
		digCnt--;
		if (digCnt < 0)
		{
			digCnt = 0;
		}
		switch (save[digCnt])
		{
		case	Direction::Up:      //��
			y += 2;
			break;
		case	Direction::Down:    //��
			y -= 2;
			break;
		case	Direction::Left:    //��
			x += 2;
			break;
		case	Direction::Right:   //�E
			x -= 2;
			break;
		}
		//�@�����L�^��1���Z�b�g
		save[digCnt] = Direction::None;
	}

}
