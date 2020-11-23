#pragma once
#include "Destructible.h"
#include "GameLogic.h"


class Asteroid : public Destructible
{
public:
	Asteroid(int x, int y);
	~Asteroid();
	void tick(float deltaTime);
};