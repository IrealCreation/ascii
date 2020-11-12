#pragma once

// ----- Headers -----
#include "Actor.h"
// -------------------

// ----- Classe -----
/// <summary>
///	Abstract class for an actor that can receive damages and be destroyed
/// </summary>
class Destructible : public Actor
{
public:
	// ----- Constructeur/Destructeur -----
	Destructible(int x, int y, int health, std::string visualAspect);
	Destructible(int x, int y, int health, std::string visualAspect, int color);

	~Destructible();
	// ------------------------------------


	// ----- Méthodes -----
	bool ReceiveDamages(int damages);
	void Destroy();
	// --------------------


protected:
	int m_health = 100;


};
// ------------------

