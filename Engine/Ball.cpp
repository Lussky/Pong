#include "Ball.h"

Ball::Ball( float in_x, float in_y, float in_vx, float in_vy,
	Color in_c, int in_dirx, int in_diry )
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	c = in_c;
	DirectionX = in_dirx;
	DirectionY = in_diry;
}

void Ball::Draw(Graphics & gfx) const
{
	gfx.DrawCircle( x, y, radius, c );
}

void Ball::Move()
{
	switch ( DirectionX )
	{
		case 1:
		{
			x += vx;
		}
		break;

		case 2:
		{
			x -= vx;
		}
		break;
	}
	
	switch ( DirectionY )
	{
		case 1:
		{
			y += vy;
		}
		break;

		case 2:
		{
			y -= vy;
		}
		break;
	}
}

void Ball::ClampScreenX()
{
	static constexpr float MaxBorderX = Graphics::ScreenWidth;

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
}

void Ball::ClampScreenY()
{
	static constexpr float MaxBorderY = Graphics::ScreenHeight;

	if (y - radius < 0)
	{
		y = radius;
		vy = -vy;
	}
	if (y + radius > MaxBorderY)
	{
		y = MaxBorderY - radius;
		vy = -vy;
	}
}

void Ball::Collision( float x1, float width1, float y1, float height1 )
{
	const float right_p = x1 + width1;
	const float bottom_p = y1 + height1;

	const float left_b = x - radius;
	const float right_b = x + radius;
	const float top_b = y - radius;
	const float bottom_b = y + radius;

	if ( left_b <= right_p &&
		 top_b <= bottom_p &&
		 bottom_b >= y1 && 
		 right_b >= x1 )
	{
		vx = -vx;
	}

}

void Ball::Reset( float in_x, float in_y, int velx, int vely )
{
	static constexpr float MaxBorderX = Graphics::ScreenWidth;

	if ((x - radius < 0) ||
		(x + radius > MaxBorderX))
	{
		x = in_x;
		y = in_y;
		DirectionX = velx;
		DirectionY = vely;
	}
}
