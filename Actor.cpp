#include "Actor.h"


// ----- Constructeur/Destructeur -----
Actor::Actor() {}

Actor::Actor(std::string visualAspect) : m_visualAspect(visualAspect) {}

Actor::Actor(std::string visualAspect, int color) : m_visualAspect(visualAspect), m_color(color) {}

Actor::~Actor() {}
// -----------------------------------

// ----- Get -----
int Actor::getPositionX() { return m_positionX; }
int Actor::getPositionY() { return  m_positionY; }
std::string Actor::getVisualAspect() { return m_visualAspect; }
int Actor::getColor() { return m_color; }
// ---------------

// ----- Set -----
void Actor::setPositionY(int amount)
{
	m_positionY += amount;
}