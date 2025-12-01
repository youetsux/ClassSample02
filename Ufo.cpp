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
    Vector2D pos = GetPos();
    Vector2D vel = GetVel();

    pos.x += vel.x*gDeltaTime;

    const float LEFT_LIMIT = 50.0f;
    const float RIGHT_LIMIT = (float)(WIN_WIDTH - 50);

    if (pos.x < LEFT_LIMIT)
    {
        pos.x = LEFT_LIMIT;
        vel.x = -vel.x;
    }
    else if (pos.x > RIGHT_LIMIT)
    {
        pos.x = RIGHT_LIMIT;
        vel.x = -vel.x;
    }

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

    // UFOñ{ëÃÅiâ~Åj
    DrawCircle(cx, cy, radius_, bodyColor, TRUE);

    // ògê¸
    DrawCircle(cx, cy, radius_, outlineColor, FALSE);
}
