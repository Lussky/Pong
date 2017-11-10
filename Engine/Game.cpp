/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd() ),
	vx( 1,2 ),
	vy( 1, 2 ),
	p1( 50,240,Colors::White, 2 ),
	p2( 750, 240, Colors::White, 1 ),
	ball( 400, 300, -4, -4, Colors::White, vx( rng ), vy( rng ) )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	p1.Move( wnd );
	p1.ClampScreen();
	p2.Move(wnd);
	p2.ClampScreen();
	ball.Move();
	ball.Reset( 400, 300, vx( rng ), vy( rng ) );
	ball.ClampScreenX();
	ball.ClampScreenY();
	ball.Collision( p1.GetX(), p1.GetWidth(), p1.GetY(), p1.GetHeight() );
	ball.Collision( p2.GetX(), p2.GetWidth(), p2.GetY(), p2.GetHeight() );
}

void Game::ComposeFrame()
{
	p1.Draw( gfx );
	p2.Draw( gfx );
	ball.Draw( gfx );
}
