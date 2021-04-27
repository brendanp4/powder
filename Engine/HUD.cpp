#include "HUD.h"
#include "Sprite.h"

HUD::Selection HUD::returnSelection()
{
	CheckSelection();
	if (selection == Selection::sand) {
		return Selection::sand;
	}
	else if (selection == Selection::water) {
		return Selection::water;
	}
}

void HUD::Draw(Graphics & gfx)
{
	for (int w = 0; w < width; w++)
	{
		for (int h = 0; h < height; h++)
		{
			gfx.PutPixel(posX + w, posY + h, 40, 60, 60);
		}
	}
	DrawCells(gfx);
}

void HUD::DrawCells(Graphics & gfx)
{
	DrawIcons(gfx);
	for (int i = 0; i < cellElements; i++)
	{
		int x = posX + offsetX + ((40 + offsetX) * i);
		int y = posY;
		cellAt(x).DrawCell(gfx, x, y);
	}
	
}

void HUD::DrawIcons(Graphics & gfx)
{
	Sprite::DrawWater(gfx, 150, 505);
}

bool HUD::MouseInCell(int x, int y)
{
	for(Cell c : cell)
	{
		if (y >= 505 && y <= 545) {
			if (x >= c.GetLeft() && x <= c.GetRight()) {
				return true;
			}
		}
		else {
			return false;
		}
	}
	
}

void HUD::CheckHover(int x, int y)
{
	/*if (y >= 505 && y <= 545) {
		cellAt(x).Hover();
	}
	else if(y < 505 || y > 545)
	{
		cellAt(x).Unhover();
	}*/


	// This doesn't work, need to hard code for each indivual cell if statements

	if (y >= 505 && y <= 545) {
		//Cell c = cellAt(x);
		if (x >= 105 && x <= 145) {
			cell[0].Hover();
		}
		else
		{
			cell[0].Unhover();
		}
		if (x >= 150 && x <= 190) {
			cell[1].Hover();
		}
		else
		{
			cell[1].Unhover();
		}
		if (x >= 195 && x <= 235) {
			cell[2].Hover();
		}
		else
		{
			cell[2].Unhover();
		}
		if (x >= 240 && x <= 280) {
			cell[3].Hover();
		}
		else
		{
			cell[3].Unhover();
		}
		if (x >= 285 && x <= 325) {
			cell[4].Hover();
		}
		else
		{
			cell[4].Unhover();
		}
	}
	

	//for (int i = 0; i < cellElements; i++);
	//{
	//	Cell& c = cellAt(x);
	//	int left = c.GetLeft();
	//	int right = c.GetRight();
	//	if (y >= 505 && y <= 545) {
	//		if (x >= left && x <= right) {
	//		}
	//	}
	//	else {
	//		c.Unhover();
	//	}
	//}

}

void HUD::CheckClick(int x, int y)
{
	if (y >= 505 && y <= 545) {
		//Cell c = cellAt(x);
		if (x >= 105 && x <= 145) {
			cell[0].Click();
			cell[0].selected = true;
		}
		else
		{
			cell[0].Unhover();
			cell[0].selected = false;
		}
		if (x >= 150 && x <= 190) {
			cell[1].Click();
			cell[1].selected = true;
		}
		else
		{
			cell[1].Unhover();
			cell[1].selected = false;
		}
		if (x >= 195 && x <= 235) {
			cell[2].Click();
			cell[2].selected = true;
		}
		else
		{
			cell[2].Unhover();
			cell[2].selected = false;
		}
		if (x >= 240 && x <= 280) {
			cell[3].Click();
			cell[3].selected = true;
		}
		else
		{
			cell[3].Unhover();
			cell[3].selected = false;
		}
		if (x >= 285 && x <= 325) {
			cell[4].Click();
			cell[4].selected = true;
		}
		else
		{
			cell[4].Unhover();
			cell[4].selected = false;
		}
	}
}

void HUD::CheckSelection()
{
	if (cell[0].selected) {
		selection = Selection::sand;
	}
	if (cell[1].selected) {
		selection = Selection::water;
	}
}

HUD::Cell & HUD::cellAt(int x)
{
	int gridX = x - posX;
	if (gridX >= 5 && gridX <= 45) {
		return cell[0];

	}
	else if (gridX >= 50 && gridX <= 90) {
		return cell[1];

	}
	else if (gridX >= 95 && gridX <= 135) {
		return cell[2];

	}
	else if (gridX >= 140 && gridX <= 180) {
		return cell[3];

	}
	else if (gridX >= 185 && gridX <= 225) {
		return cell[4];

	}
	else
	{
	}
}

void HUD::Cell::DrawCell(Graphics & gfx, int x, int y)
{
	//int padding = (cellWidth + offsetX) * num;


	switch (state)
	{
	case HUD::Cell::State::unhover:
		for (int i = 0; i < cellWidth; i++) {
			for (int j = 0; j < cellWidth; j++) {
				leftCoord = x;
				rightCoord = leftCoord + cellWidth;
				gfx.PutPixel((x + i), (y + j) + offsetY, 120, 120, 120);
			}
		}
		break;
	case HUD::Cell::State::hover:
		for (int i = 0; i < cellWidth; i++) {
			for (int j = 0; j < cellWidth; j++) {
				leftCoord = x + offsetX;
				rightCoord = leftCoord + cellWidth;
				gfx.PutPixel((x + i), (y + j) + offsetY, 165, 150, 130);
			}
		}
		break;
	case HUD::Cell::State::clicked:
		for (int i = 0; i < cellWidth; i++) {
			for (int j = 0; j < cellWidth; j++) {
				leftCoord = x + offsetX;
				rightCoord = leftCoord + cellWidth;
				gfx.PutPixel((x + i), (y + j) + offsetY, 205, 205, 205);
			}
		}
		break;
	default:
		break;
	}
	
}

void HUD::Cell::Click()
{
	state = State::clicked;
}


void HUD::Cell::Hover()
{
	state = State::hover;
}

void HUD::Cell::Unhover()
{
	state = State::unhover;
}

int HUD::Cell::GetLeft()
{
	return leftCoord;
}

int HUD::Cell::GetRight()
{
	return rightCoord;
}
