#pragma once



class C_Player
{
private:
	// テクスチャ ・・・ 画像データ
	KdTexture* m_playerTex;

	// 行列 ・・・ 座標などの情報
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