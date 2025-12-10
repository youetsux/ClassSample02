#pragma once
#include "BaseChara.h"
class Balloon :
    public BaseChara
{
public:
	Balloon();
	Balloon(const Vector2D& pos, const Vector2D& vel,
		unsigned int color);
	~Balloon();
	void Update() override; //オーバーライド
	void Draw() override; //オーバーライド
private:
	int radius_;//風船の半径
	void RiseUpward(); //上昇する（Balloonクラス専用）
	double totalTime_;
};

