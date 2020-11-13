#include "Comet.h"

// ----- Constructeur/Destructeur -----
Comet::Comet(int x, int y, std::string direction, bool way, float speed) : Destructible(x, y, 10, "c")
{
	m_direction = direction;
	m_way = way;
	m_speed = speed;
	m_collisionDamages = 10;
}

Comet::~Comet() {}
// ------------------------------------


void Comet::Tick(float deltaTime)
{
	// The amount of move available this turn
	float move = deltaTime * m_speed + m_moveRemaining;

	// Let's get the integer part of the move to see what movement is actually performed this tick, and put the rest in moveRemaining
	int intMove = modff(move, &m_moveRemaining);

	// Perform the move in the programmed direction
	int newPosX = m_positionX;
	int newPosY = m_positionY;
	if(m_direction == "x")
	{
		newPosX += intMove * (m_way) ? 1 : -1;
	}
	else
	{
		newPosY += intMove * (m_way) ? 1 : -1;
	}
	MoveTo(newPosX, newPosY);
}