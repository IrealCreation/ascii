#include "Character.h"


// ----- Constructeur/Destructeur -----
Character::Character(int x, int y, int health) : Destructible(x, y, health, "v") {}

Character::~Character(){}
// ------------------------------------


void Character::tick(float deltaTime)
{
	return;
}