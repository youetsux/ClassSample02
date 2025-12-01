#pragma once
#include "BaseChara.h"

class Ufo :
    public BaseChara
{
public:
	Ufo();
	Ufo(const Vector2D& pos, const Vector2D& vel,
		unsigned int color);
	~Ufo();
	void Update() override; //オーバーライド
	void Draw() override; //オーバーライド
private:
	void RepeatMoveLeftRight(); //左右に往復移動する（Carクラス専用）
	int radius_;//UFOの半径
};

