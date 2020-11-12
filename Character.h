#pragma once

// ----- Headers -----
#include "Destructible.h"
// -------------------

// ----- Class -----
class Character : public Destructible
{

public:
	// ----- Constructeur/Destructeur -----
	Character(int x, int y, int health);
	~Character();
	// ------------------------------------


	// ----- Méthodes -----
	void Tick();
	// --------------------


protected:
	// ----- Attributs -----

	// ---------------------


};
// ------------------

