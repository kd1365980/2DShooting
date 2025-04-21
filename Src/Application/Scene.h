#pragma once
#include"maze.h"
#include"player.h"
#include"hit.h"

class Scene
{
private:
	C_Maze m_maze;
	C_Player m_player;
	C_Hit m_hit;


	// テクスチャ ・・・ 画像データ
	KdTexture blockTex;
	KdTexture playerTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

public:

	// 初期設定
	void Init();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// 解放
	void Release();

	// GUI処理
	void ImGuiUpdate();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
