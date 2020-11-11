#include "Actor.h"


// ----- Constructeur/Destructeur -----
Actor::Actor(int x, int y, std::string visualAspect) : m_positionX(x), m_positionY(y), m_visualAspect(visualAspect) {}

Actor::Actor(int x, int y, std::string visualAspect, int color) : m_positionX(x), m_positionY(y), m_visualAspect(visualAspect), m_color(color) {}

Actor::~Actor(){}
// ------------------------------------


/// <summary>
/// Move the actor to the specified coordinates
/// </summary>
/// <param name="x">X coordinate. If null, stay unchanged.</param>
/// <param name="y">Y coordinate. if null, stay unchanged.</param>
/// <returns>True if the move could be done, false otherwise</returns>
bool Actor::MoveTo(int x, int y) {
	bool valid = true;
	//TODO: check if the move can be done (maybe by the GameLogic?)

	if (valid) {
		m_positionX = (x != NULL) ? x : m_positionX;
		m_positionY = (y != NULL) ? y : m_positionY;
	}
	return valid;
}