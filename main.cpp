#include "GameLogic.h"
#include "Character.h"
#include "Comet.h"
#include "Enemy.h"

#include "Layout.h"

#include <Windows.h>
#include <conio.h>

#include <iostream>
#include <vector>


// ----- TESTS ONLY/FULLSCREEN MODE -----
/// ! Le fullscreen est lanc� avec la classe GameLogic !
/// (fonction � supprimer apr�s tests)
void fullScreen()
{
// ----- Gestion de la police d'�criture -----
CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 16;                  // Width of each character in the font
cfi.dwFontSize.Y = 16;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
wcscpy_s(cfi.FaceName, L"Verdana"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
// --------------------------------------------

// ----- Affiche en plein �cran -----
ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
// ----------------------------------

// ----- Cache la barre de titre -----
SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
// -----------------------------------

// ----- Supprime la barre de d�filement verticale -----
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(handle, &info);
COORD new_size =
{
	info.srWindow.Right - info.srWindow.Left + 1,
	info.srWindow.Bottom - info.srWindow.Top + 1
};
SetConsoleScreenBufferSize(handle, new_size);
// -----------------------------------------------------
}
// --------------------------------------


int main()
{
	// ----- D�but du jeu -----
	 GameLogic Game;
	 Game.newGame();
	// ------------------------




	/*
	// ----- Test de spawn d'actors -----
	Comet comet(10, 10, 'x', true, 1);
	comet.tick(1);
	
	// Cr�ation de la fen�tre principale
	fullScreen();
	int const sizeX(35), sizeY(35);
	Layout MainScreen(sizeX, sizeY, 1, 1);
	MainScreen.createBorders("#");
	MainScreen.setGrid(17, 17, "P"); // Position du joueur au centre
	MainScreen.refresh();

	// Cr�ation d'une fen�tre secondaire pour d�bug.
	Layout Debug(25, 15, 5, 3, MainScreen, "x");
	Debug.createBorders("#");
	Debug.setGrid(2, 3, "Position du joueur");
	Debug.setGrid(2, 6, "- Position x -");
	Debug.setGrid(2, 9, "- Position y -");
	Debug.refresh();

	// Cr�ation d'un tableaux de bool�ens pour indiquer si un objet se trouve � un endroit d�finit de la map.
	// La grille d'actors a [10][10] cases de plus. Elle commence en -5/-5 et finit en 40/40 par rapport � la fen�tre de la map ;
	// tout ce qui est en dessous de 0 et au dessus de 35 dans la grille ne s'affiche pas � l'�cran.
	bool actors[sizeX + 10][sizeY + 10];
	
	// Initialisation des �l�ments de la variable
	for (int x = 0; x < (sizeX + 10); x++)
	{
		for (int y = 0; y < (sizeY + 10); y++)
		{
			actors[x][y] = false;
		}
	}
	
	// Set un �l�ment de la variable pour TESTS
    actors[15][15] = true;

	// Display l'�l�ment s'il est pr�sent dans l'�cran
	for (int x = 0; x < (sizeX + 10); x++)
	{
		for (int y = 0; y < (sizeY + 10); y++)
		{
			if (actors[x][y] == true && x > 4 && x < 41 && y > 4 && y < 41)
			{
				MainScreen.setGrid(x - 5, y - 5, "B", 4); // On enl�ve 5 et 5 en x et y pour le positionner correctement.
			}
		}
	}
	MainScreen.refresh();

	// ----------------------------------
	*/




   //std::cout << "Hello, World!" << std::endl;
   return 0;
}

