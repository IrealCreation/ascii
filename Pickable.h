#pragma once
#include "Actor.h"


// Abstract parent class for Pickable objects


class Pickable : public Actor
{
public:
	Pickable(int x, int y, std::string visualAspect);
	virtual ~Pickable();

	void tick(float deltaTime);

private:

};