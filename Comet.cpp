#include "Comet.h"



// ----- Constructeur/Destructeur -----
Comet::Comet(int x, int y, std::string direction, bool way, float speed) : Destructible(x, y, 10, "c")
{
	m_axis = direction;
	m_direction = way;
	m_speed = speed;
	m_collisionDamages = 10;
}

Comet::~Comet() {}
// ------------------------------------


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
	/*if (m_axis == "x" && m_direction == true)
	{
		newPosX += intMove;
	}
	else if (m_axis == "x" && m_direction == false)
	{
		newPosX += intMove * (-1);
	}
	else if (m_axis == "y" && m_direction == true)
	{
		newPosY += intMove;
	}
	else if (m_axis == "y" && m_direction == false)
	{
		newPosY += intMove * (-1);
	}*/
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
