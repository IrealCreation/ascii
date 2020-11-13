#pragma once

// ----- Headers -----
#include "Actor.h"
// -------------------

/// <summary>
///	Abstract class for an actor that can receive damages and be destroyed
/// </summary>
class Destructible : public Actor
{
public:
	// ----- Constructeur/Destructeur -----
	Destructible(int x, int y, int health, std::string visualAspect);
	Destructible(int x, int y, int health, std::string visualAspect, int color);

	~Destructible();
	// ------------------------------------


	// ----- Méthodes -----
	bool ReceiveDamages(int damages);
	void Destroy();

	/// <summary>
	/// What happens when I collide with another actor?
	/// </summary>
	/// <param name="collider">The actor I collide with</param>
	void CollideWith(Actor& collider);
	// --------------------


protected:
	int m_health = 100;


};

