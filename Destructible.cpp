#include "Destructible.h"

#include "GameLogic.h"


// ----- Constructeur/Destructeur -----
Destructible::Destructible(int x, int y, int health, std::string visualAspect) : Actor(x, y, visualAspect), m_health(health) {}
Destructible::Destructible(int x, int y, int health, std::string visualAspect, int color) : Actor(x, y, visualAspect, color), m_health(health) {}

Destructible::~Destructible() {}
// ------------------------------------

/// <summary>
/// Inflict damages to this Destructible actor.
/// </summary>
/// <param name="damages"></param>
/// <returns>True if the actor is destroyed, false otherwise.</returns>
bool Destructible::receiveDamages(int damages) {
	m_health -= damages;
	if (m_health <= 0) {
		destroy();
		return true;
	}
	return false;
}

/// <summary>
/// Destroy this destructible
/// </summary>
void Destructible::destroy() {
	GameLogic::getGameLogic()->removeActor(this);

	//TODO: spawn loot?
}

void Destructible::collideWith(Actor* collider)
{
	receiveDamages(collider->getCollisionDamages());
}
