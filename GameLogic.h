#pragma once

// ----- Headers -----
#include <Windows.h>

#include <conio.h> //inputs

#include <thread> // Contrôle du timing du jeu 
#include <chrono>
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


protected:

};