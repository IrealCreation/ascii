#pragma once

// ----- Headers -----
#include <string>
// -------------------

// ----- Class -----
/// <summary>
///	Abstract class inherited by every game object appearing in the map
/// </summary>
class Actor
{
public:
	// ----- Constructeur/Destructeur -----
	Actor(int x, int y, std::string visualAspect);
	Actor(int x, int y, std::string visualAspect, int color);

	~Actor();
	// ------------------------------------


	// ----- Méthodes -----
	/// <summary>
	/// Move the actor in the game world to designated coordinates
	/// </summary>
	bool MoveTo(int x, int y);

	/// <summary>
	/// Tick should be called at each game update
	/// </summary>
	/// <param name="deltaTime">Time since last game update</param>
	virtual void Tick(float deltaTime) = 0;
	// --------------------

protected:
	// ----- Attributs -----
	int m_positionX;
	int m_positionY;
	std::string m_visualAspect = "/";
	int m_color = 7;
	// ---------------------

};
// ------------------

