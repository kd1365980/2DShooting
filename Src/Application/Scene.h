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


	// �e�N�X�`�� �E�E�E �摜�f�[�^
	KdTexture blockTex;
	KdTexture playerTex;

	// �s�� �E�E�E ���W�Ȃǂ̏��
	Math::Matrix matrix;

public:

	// �����ݒ�
	void Init();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	// ���
	void Release();

	// GUI����
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
