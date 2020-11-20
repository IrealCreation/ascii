#pragma once

// ----- Headers -----
#include "GameLogic.h"
#include "Projectile.h"
#include <string>
// -------------------

/// <summary>
///	A celestial object moving linearly and inflicting damages if collided
/// </summary>
class Comet : public Projectile
{
public:
	// ----- Constructeur/Destructeur -----
	Comet(int x, int y, char axis, bool way, float speed);

	~Comet();
	// ------------------------------------

};

