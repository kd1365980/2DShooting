#include"main.h"
#include"Scene.h"

void Scene::Init()
{
	//乱数初期化
	srand(time(0));

	// 画像の読み込み処理
	blockTex.Load("Texture/block.png");
	playerTex.Load("Texture/chara.png");

	m_maze.SetTex(&blockTex);
	m_player.SetTex(&playerTex);

	//関数呼び出し
	m_maze.Init();
	m_maze.InitMaze();
	m_player.Init();
}

void Scene::Update()
{
	//エンターキーを押したら
	//if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	//{
	//迷路を生成
	m_maze.Update();
	m_player.Update();
	//m_hit.Block();

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		//迷路を初期状態に戻す
		m_maze.InitMaze();
	}
}

void Scene::Draw2D()
{
	m_maze.Draw();
	m_player.Draw();
}

void Scene::Release()
{
	// 画像の解放処理
	blockTex.Release();
	playerTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

