#pragma once
#include "Vector2D.h"

//形状
//0:円 1:正方形 2:長方形　3:三角形

class BaseChara
{
public:
	BaseChara();
	~BaseChara();
	virtual void Update();
	virtual void Draw();
public:
	//セッター
	//ゲッター
private:
	Vector2D pos_;//位置
	Vector2D vel_;//速度
	unsigned int Color_;//色 符号なし整数
	int shape_;//形状
};

