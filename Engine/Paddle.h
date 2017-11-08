#pragma once

#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"


class Paddle
{
public:
	Paddle( int in_x, int in_y, Color in_c );
	void Draw( Graphics& gfx );
	void Move( MainWindow& wnd );
	void ClampScreen();
	bool Collision();
private:
	int x;
	int y;
	static constexpr int width = 8;
	static constexpr int height = 60;
	Color c;
};