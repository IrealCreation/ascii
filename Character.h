#pragma once

// ----- Headers -----
#include "Destructible.h"
// -------------------

class Character : public Destructible
{

public:
	// ----- Constructeur/Destructeur -----
	Character(int x, int y, int health);
	~Character();
	// ------------------------------------


	// ----- Méthodes -----
	void tick();
	// --------------------


protected:
	// ----- Attributs -----

	// ---------------------


};

