#include "Character.h"


// ----- Constructeur/Destructeur -----
Character::Character(int x, int y) : Destructible(x, y, 100, "V")
{
	m_collisionDamages = 10;
}

Character::~Character(){}
// ------------------------------------


void Character::tick(float deltaTime)
{
	return;
}