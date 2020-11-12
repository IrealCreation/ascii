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
	std::string m_direction;
	
	/// <summary>
	/// Is it moving towards positive coordinates (true), or negative coordinates?
	/// </summary>
	bool m_way;
	
	float m_speed;
	
	float m_moveRemaining;

};
// ------------------

