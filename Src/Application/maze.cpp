#include "maze.h"

void C_Maze::Init()
{
	//乱数初期化
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
	//外枠ブロック
	for (int h = 0; h < MAZE_HEIGHT; h++)
	{
		for (int w = 0; w < MAZE_WIDTH; w++)
		{
			mazeFlg[h][w] = 1;
		}
	}
	//スタート地点
	x = 1;
	y = 1;
	mazeFlg[y][x] = 0;

	//掘れるかフラグ
	digFlg = true;

	//履歴のリセット
	for (int i = 0; i < SAVE_MAX; i++)
	{
		save[i] = Direction::None;
	}
	digCnt = 0;
}

void C_Maze::CreateMaze()
{
	//=====================================================
	//迷路を掘り進める処理
	//=====================================================
	dir = (Direction)(rand() % Direction::Kind);
	switch (dir)
	{
	case	Direction::Up:      //上
		if (y - 2 >= 1 && mazeFlg[y - 2][x] == 1)
		{
			mazeFlg[y - 1][x] = 0;
			mazeFlg[y - 2][x] = 0;
			y -= 2;
			//掘った方向の記録
			save[digCnt] = Direction::Up;
			digCnt++;
		}
		break;
	case	Direction::Down:    //下
		if (y + 2 < MAZE_HEIGHT - 1 && mazeFlg[y + 2][x] == 1)
		{
			mazeFlg[y + 1][x] = 0;
			mazeFlg[y + 2][x] = 0;
			y += 2;
			//掘った方向の記録
			save[digCnt] = Direction::Down;
			digCnt++;
		}
		break;
	case	Direction::Left:    //左
		if (x - 2 >= 1 && mazeFlg[y][x - 2] == 1)
		{
			mazeFlg[y][x - 1] = 0;
			mazeFlg[y][x - 2] = 0;
			x -= 2;
			//掘った方向の記録
			save[digCnt] = Direction::Left;
			digCnt++;
		}
		break;
	case	Direction::Right:   //右
		if (x + 2 < MAZE_WIDTH - 1 && mazeFlg[y][x + 2] == 1)
		{

			mazeFlg[y][x + 1] = 0;
			mazeFlg[y][x + 2] = 0;
			x += 2;
			//掘った方向の記録
			save[digCnt] = Direction::Right;
			digCnt++;

		}
		break;
	}

	//=====================================================
	//次のフレームでどこかまだ掘れる場合はtrueにする
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
		case	Direction::Up:      //上
			y += 2;
			break;
		case	Direction::Down:    //下
			y -= 2;
			break;
		case	Direction::Left:    //左
			x += 2;
			break;
		case	Direction::Right:   //右
			x -= 2;
			break;
		}
		//掘った記録を1つリセット
		save[digCnt] = Direction::None;
	}

}
