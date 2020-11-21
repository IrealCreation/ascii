#pragma once

// ----- Headers -----
#include "Destructible.h"
#include <string>
// -------------------

/// <summary>
/// An actor that explodes and deals damages on contact
/// </summary>
class Projectile : public Destructible
{
public:
	// ----- Constructeur/Destructeur -----
	Projectile(int x, int y, int health, std::string visualAspect, char axis, bool way, float speed, int collisionDamages);

	~Projectile();
	// ------------------------------------


	// ----- Méthodes -----
	/// <summary>
	/// tick should be called at each game update
	/// </summary>
	/// <param name="deltaTime">Time since last game update in seconds</param>
	void tick(float deltaTime);

	/// <summary>
	/// What happens when I collide with another actor?
	/// </summary>
	/// <param name="collider">The actor I collide with</param>
	void collideWith(Actor* collider);
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

