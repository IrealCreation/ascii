#include "Projectile.h"

// ----- Constructeur/Destructeur -----
Projectile::Projectile(int x, int y, int health, std::string visualAspect, char axis, bool direction, float speed, int collisionDamages) : Destructible(x, y, health, visualAspect)
{
	m_axis = axis;
	m_direction = direction;
	m_speed = speed;
	m_collisionDamages = collisionDamages;
}

Projectile::~Projectile() {}
// ------------------------------------


void Projectile::tick(float deltaTime)
{
	// The amount of move available this turn
	float move = deltaTime * m_speed + m_moveRemaining;

	// Let's get the integer part of the move to see what movement is actually performed this tick, and put the rest in moveRemaining
	float completeMove = 0;
	m_moveRemaining = modff(move, &completeMove);

	// Perform the move in the programmed direction
	int newPosX = m_positionX;
	int newPosY = m_positionY;
	if (m_axis == "x")
	{
		newPosX += completeMove * ((m_direction) ? 1 : -1);
	}
	else
	{
		newPosY += completeMove * ((m_direction) ? 1 : -1);
	}
	moveTo(newPosX, newPosY);
}

void Projectile::collideWith(Actor& collider)
{
	// The comet is immediately destroyed when collided
	destroy();
}
