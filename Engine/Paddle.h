#pragma once

#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Ball.h"


class Paddle
{
public:
	Paddle( float in_x, float in_y, Color in_c, int in_player );
	void Draw( Graphics& gfx );
	void Move( MainWindow& wnd );
	void ClampScreen();
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
private:
	float x;
	float y;
	static constexpr float width = 8;
	static constexpr float height = 60;
	Color c;
	int player;
};