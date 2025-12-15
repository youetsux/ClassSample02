#include "Balloon.h"
#include <DxLib.h>
#include "globals.h"
#include <cmath>

//えへへ、かきかえちゃったよ。

Balloon::Balloon()
	: BaseChara(), radius_(15)
{
	vel_ = { 0.0f, -30.0f };//上向きに50の速度
	pos_ = { (float)GetRand(WIN_WIDTH - 1), 
		    (float)(GROUND_HEIGHT - radius_) };
	Color_ = GetColor(255, 0, 0);
	SetShape(SHAPE::CIRLCE);
	totalTime_ = 0.0;
}

Balloon::Balloon(const Vector2D& pos, const Vector2D& vel, unsigned int color)
	: BaseChara(pos, vel, color, SHAPE::CIRLCE), radius_(15), totalTime_(0.0)
{
}

Balloon::~Balloon()
{
}

void Balloon::Update()
{
	RiseUpward();
	totalTime_ += GetDeltaTime();
}

void Balloon::Draw()
{
	const float swingWidth = 50.0f;
	//posを中心として、半径15の円を描画
	float swingOffset = swingWidth * sin(totalTime_);
	DrawCircle((int)(pos_.x + swingOffset), (int)(pos_.y),
		radius_, GetCharaColor(), true);
	DrawLine(pos_.x + swingOffset, pos_.y + radius_,
		  pos_.x + swingOffset, pos_.y + radius_ + 15,
		 GetColor(255, 255, 255), 2);
}

void Balloon::RiseUpward()
{
	float dt = GetDeltaTime();
	// 現在位置取得
	pos_.y += vel_.y * dt;
	// 上端に到達したら下から再出現
	if (pos_.y < 0) {
		pos_.y = 0;
	}
}
