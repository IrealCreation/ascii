#include "Asteroid.h"


// ----- Constructor / Destructor -----
Asteroid::Asteroid(int x, int y) : Destructible(x, y, 100, "A", 3){}

Asteroid::~Asteroid()
{
	GameLogic::getGameLogic()->spawn(new PFuel(m_positionX, m_positionY));
}
// ------------------------------------

void Asteroid::tick(float deltaTime)
{
}
