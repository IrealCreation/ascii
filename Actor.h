#pragma once

// ----- Headers -----
#include <string>
// -------------------

// ----- Classe -----
class Actor
{
public:
	// ----- Constructeur/Destructeur -----
	Actor();
	Actor(std::string visualAspect);
	Actor(std::string visualAspect, int color);

	~Actor();
	// ------------------------------------

	// ----- Get -----
	int getPositionX();
	int getPositionY();
	std::string getVisualAspect();
	int getColor();
	// ---------------

	// ----- Set -----
	void setPositionY(int amount);
	// ---------------

	// ----- Méthodes -----

	// --------------------

protected:
	// ----- Attributs -----
	int m_positionX = 0;
	int m_positionY = 0;
	std::string m_visualAspect = "/";
	int m_color = 7;
	// ---------------------

};
// ------------------
