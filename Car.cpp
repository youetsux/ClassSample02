#include "globals.h" //地面の高さを使いたい
#include "Car.h"
#include <DxLib.h>

namespace
{
	const int CAR_W = 50;
	const int CAR_H = 25;
}


Car::Car()
	:BaseChara(),w_(CAR_W),h_(CAR_H)
{
}

Car::Car(const Vector2D& pos, const Vector2D& vel, unsigned int color)
	:BaseChara(pos, vel, color, SHAPE::RECTANGLE), w_(CAR_W), h_(CAR_H)
{
}

Car::~Car()
{
}

void Car::Update()
{
	RepeatMoveLeftRight();
}

void Car::Draw()
{
	Vector2D pos = GetPos();
	SetPos(Vector2D(pos.x, (float)(GROUND_HEIGHT - h_)));
	//posを左上として、50x25の長方形を描画
	DrawBox((int)(pos.x), (int)(pos.y),
		(int)(pos.x + w_), (int)(pos.y + h_),
		GetCharaColor(), true);
}

void Car::RepeatMoveLeftRight()
{
    float dt = GetDeltaTime();

    // 現在位置取得
    Vector2D pos = GetPos();

    // 左端・右端
    const float left = 0.0f;
    const float right = WIN_WIDTH - w_;

    // 速度は BaseChara のメンバ vel を使う
    // P' = P + speed * dt
    pos.x += GetVel().x * dt;

    // 右端に到達したら反転
    if (pos.x > right) {
        pos.x = right;
        //SetVel({ -GetVel().x, GetVel().y });
        vel_.x = -vel_.x;
    }
    // 左端に到達したら反転
    else if (pos.x < left) {
        pos.x = left;
        //SetVel({ -GetVel().x, GetVel().y });
        vel_.x = -vel_.x;
    }

    SetPos(pos);
}
