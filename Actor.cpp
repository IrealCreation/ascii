#include "Actor.h"


// ----- Constructeur/Destructeur -----
Actor::Actor(int x, int y, std::string visualAspect) : m_positionX(x), m_positionY(y), m_visualAspect(visualAspect) {}

Actor::Actor(int x, int y, std::string visualAspect, int color) : m_positionX(x), m_positionY(y), m_visualAspect(visualAspect), m_color(color) {}

Actor::~Actor(){}
// ------------------------------------

bool Actor::moveTo(int x, int y) {
	bool valid = true;

	//TODO: implement GameLogic as following
	//Actor actorAtDestination = GameLogic.GetActorAt(x, y);


	/*if (valid) {
		m_positionX = (x != NULL) ? x : m_positionX;
		m_positionY = (y != NULL) ? y : m_positionY;
	}*/
	m_positionX = x;
	m_positionY = y;
	return valid;
}

void Actor::collideWith(Actor& collider)
{
	return;
}

std::string Actor::getVisualAspect() { return m_visualAspect; }

int Actor::getColor() { return m_color; }

int Actor::getCollisionDamages() { return m_collisionDamages; }

int Actor::getPositionX() { return m_positionX; }
int Actor::getPositionY() { return m_positionY; }
void Actor::setPositionX(int x) { m_positionX = x; }
void Actor::setPositionY(int y) { m_positionY = y; }

/* Actor& GameLogic::GetActorAt(int x, int y){}

void GameLogic::DestroyActorAt(int x, int y){} */
