#pragma once

#include "Graphics.h"
#include "Paddle.h"

class Ball
{
public:
	Ball( float in_x, float in_y, float in_vx, float in_vy, Color in_c );
	void Draw( Graphics& gfx );
	void Move();
	void ClampScreen();
	void Collision( float x1, float width1, float y1, float height1 );
	void Respawn();
private:
	float x;
	float y;
	static constexpr float radius = 8;
	float vx;
	float vy;
	Color c;
};