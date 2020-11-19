#pragma once

// ----- Headers -----
#include <Windows.h>

#include <conio.h> //inputs

#include <thread> // Contrôle du timing du jeu 
#include <chrono>

#include <vector>

#include "Actor.h"
#include "Character.h"
#include "Layout.h"
// -------------------

// ----- Macros -----
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_ACTION 13 // 13 = touche entrée
// ------------------

class GameLogic
{
public:
	GameLogic();
	~GameLogic();
	
	void newGame();

	void setMap(Layout& Sreen);
	
	void addActor(Actor &element);
	void removeActor(int actorId);
	void setActorPositionOnScreen(int actorId, Layout &Screen);

	void scrolling();


protected:



private:
	// ----- Méthodes -----
	void initialisation();
	// --------------------

	// ----- Attributs -----
	std::vector<Actor*> m_spawnedActors;
	int m_mapSizeX, m_mapSizeY;
	float m_timingMs, m_timingS; // Timing du jeu en ms et s / paramètre des fonctions tick des acteurs.
	//std::string* bigGrid; // Grille large
	// ---------------------
	
};