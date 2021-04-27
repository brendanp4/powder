#include "Water.h"
Water::Water(int x_in, int y_in)
{
	x = x_in;
	y = y_in;
}

Water::Water(const Water &w)
{
	x = w.x;
	y = w.y;
}

Water::~Water()
{
}

void Water::Draw(Graphics & gfx)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			gfx.PutPixel(x + i, y + j, 125, 145, 255);
		}
	}
}

void Water::Fall(float dt)
{
	y = y + (velY * dt);
}

bool Water::OutOfBounds()
{
	if (y >= 400) {
		return true;
	}
	else
	{
		return false;
	}
}