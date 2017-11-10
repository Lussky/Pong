#include "Ball.h"

Ball::Ball( float in_x, float in_y, float in_vx, float in_vy, Color in_c )
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	c = in_c;
}

void Ball::Draw(Graphics & gfx)
{
	gfx.DrawCircle( x, y, radius, c );
}

void Ball::Move()
{
	x += vx;
	y += vy;
}

void Ball::ClampScreen()
{
	static constexpr float MaxBorderX = Graphics::ScreenWidth;
	static constexpr float MaxBorderY = Graphics::ScreenHeight;

	if ( x - radius < 0 )
	{
		x = radius;
		vx = -vx;
	}
	if ( x + radius > MaxBorderX )
	{
		x = MaxBorderX - radius;
		vx = -vx;
	}
	if ( y - radius < 0 )
	{
		y = radius;
		vy = -vy;
	}
	if ( y + radius > MaxBorderY )
	{
		y = MaxBorderY - radius;
		vy = -vy;
	}
}

void Ball::Collision( float x1, float width1, float y1, float height1 )
{
	if ( x - radius <= x1 + width1 &&
		 y - radius >= y1 &&
		 y + radius <= y1 + height1 )
	{
		x = x + radius;
		vx = -vx;
	}

}