#pragma once
#include "Particle.h"
#include "Graphics.h"
#include "Vec2.h"
#include <random>
class Sand :
	public Particle
{
public:
	Sand() = default;
	Sand(int x_in, int y_in);
	Sand(const Sand &s);
	~Sand();
	void Draw(Graphics& gfx);
	void Fall(float dt);
	bool OutOfBounds();
private:
	Vec2 screenPos;
	int x = 20;
	int y = 20;
	float velY = 600.0f;
};

