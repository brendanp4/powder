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
#include <chrono>
#include <math.h>

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
	hud.CheckHover(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
	//hud.CheckClick(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());

	if (wnd.mouse.LeftIsPressed()) {
		mouseX = wnd.mouse.GetPosX();
		mouseY = wnd.mouse.GetPosY();
		hud.CheckClick(mouseX, mouseY);
		hud.CheckSelection();
		s = hud.returnSelection();
		switch (s)
		{
		case HUD::Selection::sand:
			sand.emplace_back(mouseX, mouseY);
			break;
		case HUD::Selection::water:
			water.emplace_back(mouseX, mouseY);
			break;
		default:
			break;
		}
	}
}

void Game::ComposeFrame()
{
	using std::chrono::steady_clock;
	steady_clock::time_point start = steady_clock::now();
	for (int i = 0; i < sand.size(); i++) {
		sand[i].Draw(gfx);
		sand[i].Fall(frameRate);
		if (sand[i].OutOfBounds()) {
			sand.erase(sand.begin() + i);
		}
	}
	for (int i = 0; i < water.size(); i++) {
		water[i].Draw(gfx);
		water[i].Fall(frameRate);
		if (water[i].OutOfBounds()) {
			water.erase(water.begin() + i);
		}
	}
	hud.Draw(gfx);


	steady_clock::time_point end = steady_clock::now();
	std::chrono::duration<float> runtime = end - start;
	frameRate = runtime.count();
}
