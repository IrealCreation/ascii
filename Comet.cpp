#include "Comet.h"

// ----- Constructeur/Destructeur -----
Comet::Comet(int x, int y, std::string direction, float speed) : Destructible(x, y, 50, "c"), m_direction(direction), m_speed(speed) {}

Comet::~Comet() {}
// ------------------------------------


void Comet::Tick()
{
	//TODO: move by speed in the direction
}