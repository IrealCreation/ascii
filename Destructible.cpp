#include "Destructible.h"


// ----- Constructeur/Destructeur -----
Destructible::Destructible(int x, int y, int health, std::string visualAspect) : Actor(x, y, visualAspect), m_health = health {}
Destructible::Destructible(int x, int y, int health, std::string visualAspect, int color) : Actor(x, y, visualAspect, int color), m_health = health {}


Destructible::~Destructible() {}
// ------------------------------------

/// <summary>
/// Inflict damages to this Destructible actor.
/// </summary>
/// <param name="damages"></param>
/// <returns>True if the actor is destroyed, false otherwise.</returns>
bool ReceiveDamages(int damages) {
	m_health -= damages;
	if (damages <= 0) {
		Destroy();
		return true;
	}
	return false;
}

/// <summary>
/// Destroy this destructible
/// </summary>
void Destroy() {
	//TODO: spawn loot?

	//TODO: inform the GameLogic that I'm not here anymore.

	~Destructible();
}