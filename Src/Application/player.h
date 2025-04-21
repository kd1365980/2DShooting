#pragma once



class C_Player
{
private:
	// �e�N�X�`�� �E�E�E �摜�f�[�^
	KdTexture* m_playerTex;

	// �s�� �E�E�E ���W�Ȃǂ̏��
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix matrix;

	Math::Vector2 m_pPos;
	
public:
	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* mTex) { m_playerTex = mTex; }
	void SetPos(Math::Vector2 pos) { m_pPos = pos; }
};