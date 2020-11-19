#include "Character.h"


// ----- Constructeur/Destructeur -----
Character::Character(int x, int y) : Destructible(x, y, 100, "V") {}

Character::~Character(){}
// ------------------------------------


void Character::tick(float deltaTime)
{
	return;
}