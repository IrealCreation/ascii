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
	Comet(int x, int y, std::string direction, bool way, float speed);

	~Comet();
	// ------------------------------------


	// ----- Méthodes -----
	void Tick(float deltaTime);
	// --------------------

protected:
	// ----- Attributs -----
	std::string m_direction;
	bool m_way; // Is it moving in positive coordinates, or negative coordinates?
	float m_speed;
	float m_moveRemaining;
	// ---------------------

};
// ------------------

