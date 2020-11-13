#pragma once

// ----- Headers -----
#include "Destructible.h"
#include <string>
// -------------------

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

	/// <summary>
	/// What happens when I collide with another actor?
	/// </summary>
	/// <param name="collider">The actor I collide with</param>
	void CollideWith(Actor& collider);
	// --------------------

protected:
	/// <summary>
	/// "X" if it moves horizontally, "Y" otherwise
	/// </summary>
	std::string m_axis;
	
	/// <summary>
	/// Is it moving towards positive coordinates (true), or negative coordinates?
	/// </summary>
	bool m_direction;
	
	float m_speed;
	
	float m_moveRemaining = 0;

};

