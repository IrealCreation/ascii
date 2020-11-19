#pragma once

// ----- Headers -----
#include "Projectile.h"
#include <string>
// -------------------

/// <summary>
///	A fired projectile that will explode on contact of another actor
/// </summary>
class Missile : public Projectile
{
public:
	// ----- Constructeur/Destructeur -----
	Missile(int x, int y, char axis, bool way, int damages);

	~Missile();
	// ------------------------------------

};

