#include"main.h"
#include"Scene.h"

void Scene::Init()
{
	//����������
	srand(time(0));

	// �摜�̓ǂݍ��ݏ���
	blockTex.Load("Texture/block.png");
	playerTex.Load("Texture/chara.png");

	m_maze.SetTex(&blockTex);
	m_player.SetTex(&playerTex);

	//�֐��Ăяo��
	m_maze.Init();
	m_maze.InitMaze();
	m_player.Init();
}

void Scene::Update()
{
	//�G���^�[�L�[����������
	//if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	//{
	//���H�𐶐�
	m_maze.Update();
	m_player.Update();
	//m_hit.Block();

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		//���H��������Ԃɖ߂�
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
	// �摜�̉������
	blockTex.Release();
	playerTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// �f�o�b�O�E�B���h�E
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

