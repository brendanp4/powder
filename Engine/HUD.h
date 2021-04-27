#pragma once
#include "Graphics.h"
class HUD
{
private:
	class Cell
	{
	public:
		enum class State {
			unhover,
			hover,
			clicked
		};
		void DrawCell(Graphics& gfx, int x, int y);
		void Click();
		void Hover();
		void Unhover();
		int GetLeft();
		int GetRight();

		bool inCell = false;
		bool selected = false;
		
	private:
		State state = State::unhover;
		
		int leftCoord = 0;
		int rightCoord = 0;
		const int cellWidth = 40;
		const int cellHeight = 40;
		const int offsetX = 5;
		const int offsetY = 5;
		
	};
public:

	enum class Selection
	{
		sand,
		water,
		wall
	};

	Selection returnSelection();

	void Draw(Graphics& gfx);
	void DrawCells(Graphics& gfx);
	void DrawIcons(Graphics& gfx);
	bool MouseInCell(int x, int y);
	void CheckHover(int x, int y);
	void CheckClick(int x, int y);
	void CheckSelection();
private:
	Selection selection = Selection::sand;
	static constexpr int cellElements = 5;
	const int offsetX = 5;
	Cell cell[cellElements];
	Cell& cellAt(int x);
	static constexpr int posX = 100;
	static constexpr int posY = 500;
	const int width = 600;
	const int height = 50;
};

