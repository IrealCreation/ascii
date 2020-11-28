#include "Ephemeral.h"

#include "GameLogic.h"

// ----- Constructeur/Destructeur -----
Ephemeral::Ephemeral(int x, int y, std::string visualAspect, int color, float time) : Actor(x, y, visualAspect, color), m_timeLeft(time)
{
	m_collision = false;
}

Ephemeral::~Ephemeral() {}
// ------------------------------------

void Ephemeral::tick(float deltaTime)
{
	m_timeLeft -= deltaTime;

	if(m_timeLeft <= 0)
	{
		// My time is up: I will disappear into nothingness
		GameLogic::getGameLogic()->removeActor(this);
	}
}