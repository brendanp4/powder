#pragma once
#include "Graphics.h"
class Water
{
public:
	Water() = default;
	Water(int x_in, int y_in);
	Water(const Water &w);
	~Water();
	void Draw(Graphics& gfx);
	void Fall(float dt);
	bool OutOfBounds();
private:
	int x = 20;
	int y = 20;
	float velY = 600.0f;
};

