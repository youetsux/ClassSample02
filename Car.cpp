#include "Car.h"
#include <DxLib.h>

Car::Car()
	:BaseChara()
{
}

Car::Car(const Vector2D& pos, const Vector2D& vel, unsigned int color)
	:BaseChara(pos, vel, color, SHAPE::RECTANGLE)
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
	//pos‚ğ¶ã‚Æ‚µ‚ÄA50x25‚Ì’·•ûŒ`‚ğ•`‰æ
	DrawBox((int)(pos.x), (int)(pos.y),
		(int)(pos.x + 50.0f), (int)(pos.y + 25.0f),
		GetCharaColor(), true);
}

void Car::RepeatMoveLeftRight()
{
}
