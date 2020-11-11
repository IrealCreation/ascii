#include "Actor.h"


// ----- Constructeur/Destructeur -----
Actor::Actor(){}

Actor::Actor(std::string visualAspect) : m_visualAspect(visualAspect) {}

Actor::Actor(std::string visualAspect, int color) : m_visualAspect(visualAspect), m_color(color) {}

Actor::~Actor(){}
// ------------------------------------