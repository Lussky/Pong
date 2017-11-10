#pragma once

#include "Graphics.h"
#include "Paddle.h"

class Ball
{
public:
	Ball( float in_x, float in_y, float in_vx, float in_vy, 
		Color in_c, int in_dirx, int in_diry );
	void Draw( Graphics& gfx ) const;
	void Move();
	void ClampScreenX();
	void ClampScreenY();
	void Collision( float x1, float width1, float y1, float height1 );
	void Reset( float in_x, float in_y, int velx, int vely );
private:
	float x;
	float y;
	static constexpr float radius = 8;
	float vx;
	float vy;
	Color c;
	int DirectionX;
	int DirectionY;
};