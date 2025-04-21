#pragma once

//����
enum Direction
{
	Up,           //0:��
	Down,         //1:��
	Left,         //2:��
	Right,        //3:�E
	Kind,         //4:��ސ�
	None = 999    //999:�܂��@���Ă��Ȃ�
};

class C_Maze
{
private:

	// �e�N�X�`�� �E�E�E �摜�f�[�^
	KdTexture* m_blockTex;

	// �s�� �E�E�E ���W�Ȃǂ̏��
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix matrix;

	//���H�̕�
	static const int MAZE_WIDTH = 21;//��
	static const int MAZE_HEIGHT = 11;//�c
	//���H�t���O
	int mazeFlg[MAZE_HEIGHT][MAZE_WIDTH];

	//�L�[����
	bool keyFlg;//true:	������Ă���	false:	������Ă��Ȃ�

	Direction dir;// 0:�� 1:�� 2:�� 3:�E

	int x, y;
	
	//�@��邩�t���O
	bool digFlg;

	//�@���������̍ő�Z�[�u��
	static const int SAVE_MAX = 200;
	//�@��������
	Direction save[SAVE_MAX];
	//�@������
	int digCnt;

	//�L�����̈ʒu
	Math::Vector2 player;

	//�ǂ̈ʒu
	Math::Vector2 m_bPos[MAZE_HEIGHT][MAZE_WIDTH];

public:

	void Init();
	void Update();
	void Draw();

	//���H������
	void InitMaze();

	//���H�𐶐�
	void CreateMaze();

	void SetTex(KdTexture* mTex) { m_blockTex = mTex; }

	int GetHEIGHT() { return MAZE_HEIGHT; }
	int GetWIDTH() { return MAZE_WIDTH; }
	int GetRadius() { return (64 * 3) / 2; }
	Math::Vector2 GetPos(int i,int j) { return m_bPos[i][j]; }

};