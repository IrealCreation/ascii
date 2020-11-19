#include "Comet.h"



// ----- Constructeur/Destructeur -----
Comet::Comet(int x, int y, char axis, bool direction, float speed) : Projectile(x, y, 10, "c", axis, direction, speed, 10) {}

Comet::~Comet() {}
// ------------------------------------

/*
void Comet::tick(float deltaTime)
{
	// The amount of move available this turn
	float move = deltaTime * m_speed + m_moveRemaining;

	// Let's get the integer part of the move to see what movement is actually performed this tick, and put the rest in moveRemaining
	float intMove = 0;
	m_moveRemaining = modff(move, &intMove);

	// Perform the move in the programmed direction
	int newPosX = m_positionX;
	int newPosY = m_positionY;
	int orientation = 0;
	if(m_axis == "x")
	{
		orientation = (m_direction) ? 1 : -1;
		newPosX += intMove * orientation;
	}
	else
	{
		orientation = (m_direction) ? 1 : -1;
		newPosY += intMove * orientation;
	}

	moveTo(newPosX, newPosY);
}

void Comet::collideWith(Actor& collider)
{
	// The comet is immediately destroyed when collided
	destroy();
}
*/
