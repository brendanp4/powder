#include "Sand.h"

Sand::Sand(int x_in, int y_in)
{
	x = x_in;
	y = y_in;
}

Sand::Sand(const Sand &s)
{
	x = s.x;
	y = s.y;
}

Sand::~Sand()
{
}

void Sand::Draw(Graphics & gfx)
{
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		gfx.PutPixel(x + i, y + j, 241, 247, 147);
	//	}
	//}
	gfx.PutPixel(x, y, 241, 247, 147);
}

void Sand::Fall(float dt)
{
	y = y + (velY * dt);
}

bool Sand::OutOfBounds()
{
	if (y >= 400) {
		return true;
	}
	else
	{
		return false;
	}
}
