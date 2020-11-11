#pragma once

// ----- Headers -----
#include "Actor.h"
// -------------------

// ----- Classe -----
class Destructible : public Actor
{
	// A destructible is an actor that can receive damages and be destroyed

	public:
		// ----- Constructeur/Destructeur -----
		Destructible(int x, int y, int health, std::string visualAspect);
		Destructible(int x, int y, int health, std::string visualAspect, int color);
		// ------------------------------------


		// ----- Méthodes -----
		bool ReceiveDamages(int damages);
		void Destroy();
		// --------------------


	protected:
		// ----- Attributs -----
		int m_health = 100;
		// ---------------------


};
// ------------------

