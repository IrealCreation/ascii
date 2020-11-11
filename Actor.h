#pragma once

// ----- Headers -----
#include <string>
// -------------------

// ----- Classe -----
class Actor
{
	public:
	// ----- Constructeur/Destructeur -----
		Actor(int x, int y, std::string visualAspect);
		Actor(int x, int y, std::string visualAspect, int color);

		~Actor();
	// ------------------------------------


	// ----- Méthodes -----
		bool MoveTo(int x, int y);
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

