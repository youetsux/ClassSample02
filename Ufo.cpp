#include "Ufo.h"

#include "Ufo.h"
#include <DxLib.h>
#include "globals.h"
#include <cmath>

Ufo::Ufo()
    : BaseChara()
    , radius_(20)
{
    SetShape(SHAPE::CIRLCE);
}

Ufo::Ufo(const Vector2D& pos, const Vector2D& vel,
    unsigned int color)
    : BaseChara(pos, vel, color, SHAPE::CIRLCE)
    , radius_(20)
{
}

Ufo::~Ufo()
{
}

void Ufo::Update()
{
    RepeatMoveLeftRight();
}

void Ufo::RepeatMoveLeftRight()
{
    // -------------- 今の位置と速度を取得する --------------
    Vector2D pos = GetPos();   // UFO の現在位置（どこにいるか）
    Vector2D vel = GetVel();   // UFO の速度（右向きか、左向きか）

    // -------------- 位置を更新する -------------------------
    // pos.x = pos.x + vel.x * gDeltaTime;
    // 「速度 × 経過時間」で、なめらかに左右に動かす
    pos.x += vel.x * gDeltaTime;

    // -------------- 動ける範囲（画面端）を設定 --------------
    // 左端は 50 ピクセル、右端は画面幅 - 50 ピクセル
    const float LEFT_LIMIT = 50.0f;
    const float RIGHT_LIMIT = (float)(WIN_WIDTH - 50);

    // -------------- 左に行きすぎたら -----------------------
    if (pos.x < LEFT_LIMIT)
    {
        pos.x = LEFT_LIMIT; // 左端以内に位置を戻す
        vel.x = -vel.x;     // 速度の向きを反転（右へ向かう）
    }
    // -------------- 右に行きすぎたら -----------------------
    else if (pos.x > RIGHT_LIMIT)
    {
        pos.x = RIGHT_LIMIT; // 右端以内に位置を戻す
        vel.x = -vel.x;      // 速度の向きを反転（左へ向かう）
    }

    // -------------- 位置と速度を保存 ------------------------
    // 変更した pos と vel をUFOに反映する
    SetPos(pos);
    SetVel(vel);
}

void Ufo::Draw()
{
    Vector2D pos = GetPos();

    int cx = (int)pos.x;
    static float t = 0.0f;
    int cy = (int)pos.y + 10.0f * sin(20.0f*t);
    t = t + gDeltaTime;

    unsigned int bodyColor = GetCharaColor();
    unsigned int windowColor = GetColor(200, 255, 255);
    unsigned int outlineColor = GetColor(0, 0, 0);

    // UFO本体（円）
    DrawCircle(cx, cy, radius_, bodyColor, TRUE);

    // 枠線
    DrawCircle(cx, cy, radius_, outlineColor, FALSE);
}
