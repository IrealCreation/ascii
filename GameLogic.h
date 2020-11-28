#pragma once

// ----- Headers -----
#include <Windows.h>

#include <conio.h> //inputs

#include <thread> // Contrôle du timing du jeu 
#include <chrono>

#include <time.h> // Utilisation de l'aléatoire.
#include <random> 

#include <vector>

#include "Actor.h"
#include "Character.h"
#include "Comet.h"
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

	static GameLogic* getGameLogic();

	// Actors interactions
	bool isLocationEmpty(int x, int y);
	Actor* getActor(int x, int y);
	Character* getCharacter();
	void removeActor(Actor* actor, bool spawnDebris = false);

	void spawn(Actor *actor);

protected:

private:
	// ----- Méthodes -----
	void initialisation();

	void inputs();

	void moveCharacterTowards(int x, int y);

	// Spawn/Despawn
	void spawn();
	void removeActor(int actorId);
	float randomSpeed();

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
	static GameLogic* m_mainGameLogic;
	int m_mapSizeX, m_mapSizeY, m_hiddenPart; // Dimensions de la map
	float m_timingMs, m_timingS; // Timing du jeu en ms et s / paramètre des fonctions tick des acteurs.
	float m_speedMin, m_speedMax;
	// ---------------------
	
};