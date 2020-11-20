#pragma once

// ----- Headers -----
#include <Windows.h>

#include <conio.h> //inputs

#include <thread> // Contrôle du timing du jeu 
#include <chrono>

#include <time.h> // Utilisation de l'aléatoire.
#include <random> 

#include <vector>
#include <typeinfo>

#include "Actor.h"
#include "Character.h"
#include "Comet.h"
#include "Enemy.h"
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
  

	// Actors interactions
	bool isLocationEmpty(int x, int y);
	Actor& getActor(int x, int y);
	Character* getCharacter();
	void removeActor(Actor& actor);

	void spawn(Actor *actor);

	// Actors count
	void counterAdd(std::string type);
	void counterSubstract(std::string type);

protected:

private:
	// ----- Méthodes -----
	void initialisation();

	void inputs();

	// Spawn/Despawn
	void spawn();
	int spawnSelection();
	void removeActor(int actorId);
	float randomSpeed();
	int randomInt(int rangeFrom, int rangeTo);

	// Display
	int getActorXPositionOnScreen(int actorId, Layout& Screen);
	int getActorYPositionOnScreen(int actorId, Layout& Screen);
	void removeAllActorsFromScreen(Layout& Screen);
	void setActorPositionOnScreen(int actorId, Layout& Screen);

	// Game information
	int getActorIdByLocation(int x, int y);
	Actor& getActor(int actorId);
	// --------------------


	// ----- Attributs -----
	std::vector<Actor*> m_spawnedActors;
	Character* m_mainCharacter;
	int m_mapSizeX, m_mapSizeY, m_hiddenPart; // Dimensions de la map
	float m_timingMs, m_timingS; // Timing du jeu en ms et s / paramètre des fonctions tick des acteurs.
	
	float m_speedMin, m_speedMax;
	
	int m_actorsAmountLimit;
	int m_asteroidsCounter, m_cometsCounter; // Counters
	// ---------------------
	
};