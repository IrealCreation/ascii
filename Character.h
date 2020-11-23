#pragma once

// ----- Headers -----
#include "Destructible.h"
// -------------------

class Character : public Destructible
{

public:
	// ----- Constructeur/Destructeur -----
	Character(int x, int y);
	~Character();
	// ------------------------------------


	// ----- Méthodes -----
	void tick(float deltaTime);
	// --------------------


protected:
	// ----- Attributs -----
	int m_health = 100;
	// ---------------------


};