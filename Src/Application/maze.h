#pragma once

//方向
enum Direction
{
	Up,           //0:上
	Down,         //1:下
	Left,         //2:左
	Right,        //3:右
	Kind,         //4:種類数
	None = 999    //999:まだ掘っていない
};

class C_Maze
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture* m_blockTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix matrix;

	//迷路の幅
	static const int MAZE_WIDTH = 21;//横
	static const int MAZE_HEIGHT = 11;//縦
	//迷路フラグ
	int mazeFlg[MAZE_HEIGHT][MAZE_WIDTH];

	//キー制御
	bool keyFlg;//true:	押されている	false:	押されていない

	Direction dir;// 0:上 1:下 2:左 3:右

	int x, y;
	
	//掘れるかフラグ
	bool digFlg;

	//掘った履歴の最大セーブ数
	static const int SAVE_MAX = 200;
	//掘った履歴
	Direction save[SAVE_MAX];
	//掘った回数
	int digCnt;

	//キャラの位置
	Math::Vector2 player;

	//壁の位置
	Math::Vector2 m_bPos[MAZE_HEIGHT][MAZE_WIDTH];

public:

	void Init();
	void Update();
	void Draw();

	//迷路初期化
	void InitMaze();

	//迷路を生成
	void CreateMaze();

	void SetTex(KdTexture* mTex) { m_blockTex = mTex; }

	int GetHEIGHT() { return MAZE_HEIGHT; }
	int GetWIDTH() { return MAZE_WIDTH; }
	int GetRadius() { return (64 * 3) / 2; }
	Math::Vector2 GetPos(int i,int j) { return m_bPos[i][j]; }

};