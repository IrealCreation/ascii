#pragma once
#include "Actor.h"

/// <summary>
/// A temporary actor without collision, only here for visual effects
/// </summary>
class Ephemeral : public Actor
{
public:
	// ----- Constructeur/Destructeur -----
	Ephemeral(int x, int y, std::string visualAspect, int color, float time);

	~Ephemeral();
	// ------------------------------------

	/// <summary>
	/// tick should be called at each game update
	/// </summary>
	/// <param name="deltaTime">Time since last game update in seconds</param>
	void tick(float deltaTime);

protected:
	/// <summary>
	/// Time (in seconds) before I disappear
	/// </summary>
	float m_timeLeft = 0;
	
};

