#include "Paddle.h"

Paddle::Paddle( float in_x, float in_y, Color in_c, int in_player )
{
	x = in_x;
	y = in_y;
	c = in_c;
	player = in_player;
}

void Paddle::Draw( Graphics& gfx )
{
	gfx.DrawRect(x, y, width, height, c);
}

void Paddle::Move( MainWindow& wnd )
{
	switch (player)
	{
	case 1:
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			y -= 5;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			y += 5;
		}
		break;
	
	case 2:
		if (wnd.kbd.KeyIsPressed('W'))
		{
			y -= 5;
		}
		if (wnd.kbd.KeyIsPressed('S'))
		{
			y += 5;
		} 
		break;
	}
}

void Paddle::ClampScreen()
{
	static constexpr int MaxBorder = Graphics::ScreenHeight;

	if ( y < 0 )
	{
		y = 0;
	}
	if ( y + height > MaxBorder )
	{
		y = MaxBorder - height;
	}
}

float Paddle::GetX()
{
	return x;
}

float Paddle::GetY()
{
	return y;
}

float Paddle::GetWidth()
{
	return width;
}

float Paddle::GetHeight()
{
	return height;
}
