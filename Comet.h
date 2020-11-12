#pragma once

// ----- Headers -----
#include "Destructible.h"
#include <string>
// -------------------

// ----- Class -----
/// <summary>
///	A celestial object moving linearly and inflicting damages if collided
/// </summary>
class Comet : public Destructible
{
public:
	// ----- Constructeur/Destructeur -----
	Comet(int x, int y, std::string direction, float speed);

	~Comet();
	// ------------------------------------


	// ----- M�thodes -----
	void Tick();
	// --------------------

protected:
	// ----- Attributs -----
	std::string m_direction;
	float m_speed;
	// ---------------------

};
// ------------------

