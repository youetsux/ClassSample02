#pragma once
#include "BaseChara.h"
class Rocket :
    public BaseChara
{
public:
	Rocket();
	//Rocket(int base, int height, 
	//	   const Vector2D& pos, const Vector2D& vel, unsigned int color);
	//Rocket(const Vector2D& pos, const Vector2D& vel,
	//	unsigned int color);
	~Rocket();
	void Update() override; //オーバーライド
	void Draw() override; //オーバーライド
	void LaunchRocket(); //ロケットを発射する
private:
	int baseWidth_;//底辺の幅
	int height_;//高さ
	bool isAlive_;//今飛んでるかどうか？ 
	//true:飛んでる false:止まってる

};

