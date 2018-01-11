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
#include "Mat.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
}

void Game::ComposeFrame()
{
	_vec<float> a1 = {-0.25, -0.25};
	_vec<float> a2 = { 0.25, -0.25};
	_vec<float> a3 = { 0.25, 0.25 };
	_vec<float> a4 = { -0.25, 0.25 };

	a1 = Mat::rotate(a1, wnd.mouse.GetPosX());
	a2 = Mat::rotate(a2, wnd.mouse.GetPosX());
	a3 = Mat::rotate(a3, wnd.mouse.GetPosX());
	a4 = Mat::rotate(a4, wnd.mouse.GetPosX());

	Vei2 converted_a1 =  Mat::conv(a1);
	Vei2 converted_a2 = Mat::conv(a2);
	Vei2 converted_a3 = Mat::conv(a3);
	Vei2 converted_a4 = Mat::conv(a4);

	gfx.DrawLine(converted_a1, converted_a2, Colors::White);
	gfx.DrawLine(converted_a2, converted_a3, Colors::White);
	gfx.DrawLine(converted_a3, converted_a4, Colors::White);
	gfx.DrawLine(converted_a4, converted_a1, Colors::White);
}
