#include "Rocket.h"
#include "Input.h"
#include <DxLib.h>
#include "globals.h" // WIN_WIDTH, WIN_HEIGHT, gDeltaTime, GROUND_HEIGHT

namespace
{
    const int ROCKET_WIDTH = 30;
    const int ROCKET_HEIGHT = 60;
}


Rocket::Rocket()
    : BaseChara()
    , baseWidth_(ROCKET_WIDTH)
    , height_(ROCKET_HEIGHT)
    , isAlive_(false)
{
    SetShape(TRIANGLE);
}

//Rocket::Rocket(int base, int height,
//    const Vector2D& pos, const Vector2D& vel, unsigned int color)
//    : BaseChara(pos, vel, color, TRIANGLE)
//    , baseWidth_(base)
//    , height_(height)
//    , isAlive_(false)
//{
//}
//
//Rocket::Rocket(const Vector2D& pos, const Vector2D& vel,
//    unsigned int color)
//    : BaseChara(pos, vel, color, TRIANGLE)
//    , baseWidth_(30)
//    , height_(60)
//    , isAlive_(false)
//{
//}

Rocket::~Rocket()
{
    //今のところなんもしない
}

void Rocket::LaunchRocket()
{
    // 飛行中は処理しない
    if (isAlive_) return;

	int mx = 0; // マウスX座標（適当に初期化）
	int my = 0; // マウスY座標（適当に初期化）
    GetMousePoint(&mx, &my);

    // マウスが画面内にあるか確認する
    if (mx < 0 || mx >= WIN_WIDTH) return;

    // 位置を設定（Yは必ず地面の高さ）
    //Vector2D pos;
    pos_ = { (float)(mx), (float)(GROUND_HEIGHT) };
    vel_ = { 0.0f, -50.0f };
    isAlive_ = true;
  
}

void Rocket::Update()
{
    // 飛んでいない時にスペースキーで発射
    if (!isAlive_)
    {
        if (Input::IsKeyDown(KEY_INPUT_SPACE))
        {
            LaunchRocket();
        }
        return;
    }

    //↓飛んでるとき

    //SetVel({ 0.0f, vel_.y * 1.05f });

	vel_.y = vel_.y * 1.02f; // 上昇速度を増加させる
    pos_.y = pos_.y + vel_.y * gDeltaTime;

    // 画面上部で消す
    if (pos_.y + height_ < 0.0f)
    {
        isAlive_ = false;
    }

}

void Rocket::Draw()
{
    // 死んでる時は描画しない
    if (!isAlive_) return;

    unsigned int col = GetCharaColor();

    // 上向き三角形
    int x1 = (int)pos_.x;                  // 上頂点
    int y1 = (int)pos_.y - height_ / 2;

    int x2 = (int)pos_.x - baseWidth_ / 2; // 左下
    int y2 = (int)pos_.y + height_ / 2;

    int x3 = (int)pos_.x + baseWidth_ / 2; // 右下
    int y3 = (int)pos_.y + height_ / 2;

    DrawTriangle(x1, y1, x2, y2, x3, y3, col, TRUE);
}
