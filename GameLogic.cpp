#include "GameLogic.h"
#include "Layout.h"

// _getch() pour récupérer les inputs du joueur

// ----- Constructeurs -----
GameLogic::GameLogic()
{
	initialisation();
}
// -------------------------

// ----- Destructeur -----
GameLogic::~GameLogic(){}
// ------------------------

// ----- Initialisation -----
void GameLogic::initialisation()
{
	// ----- Gestion de la police d'écriture -----
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 16;                  // Width of each character in the font
	cfi.dwFontSize.Y = 16;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Verdana"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	// --------------------------------------------

	// ----- Affiche en plein écran -----
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	// ----------------------------------

	// ----- Cache la barre de titre -----
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	// -----------------------------------

	// ----- Supprime la barre de défilement verticale -----
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
// --------------------------

// ----- New Game -----
void GameLogic::newGame()
{

	// ----- Menu principal -----
	// ----- Création du Menu -----
	std::string borders = "+";
	Layout MainMenu(36, 36, 40, 5);
	MainMenu.createBorders(borders);
	MainMenu.setGrid(14, 2, "Asteroids", 3);
	MainMenu.setGrid(5, 4, "Space Constellations", 9);
	MainMenu.setGrid(5, 5, "and Introverse Implications", 9);
	MainMenu.setGrid(12, 16, "> New Game");
	MainMenu.setGrid(14, 18, "Quit Game");
	MainMenu.refresh();
	// ----------------------------

	//int c = 0;
	//switch ((c=_getch())){...}
	int cursorPosition = 0;
	while (1)
	{
		// ----- Sélection d'une action dans le menu principal -----
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Attendre 50ms
		BlockInput(false); // Autorise les inputs du joueur
		switch (_getch())
		{
		case KEY_UP:
			if (cursorPosition == 1)
			{
				cursorPosition = 0;
				break;
			}
			else
			{
				cursorPosition = 0;
				break;
			}
		case KEY_DOWN:
			if (cursorPosition == 0)
			{
				cursorPosition = 1;
				break;
			}
			else
			{
				cursorPosition = 1;
				break;
			}
		case KEY_ACTION:
			if (cursorPosition == 0)
			{
				// NEW GAME
				//printf("new");
				break;
			}
			else if (cursorPosition == 1)
			{
				// QUIT GAME
				//printf("quit");
				break;
			}
		}
		BlockInput(true); // Interdit les inputs du joueur
		// ---------------------------------------------------------

		// ----- Change la position du curseur -----
		if (cursorPosition == 0) // Curseur sur Nouvelle partie
		{
			MainMenu.setGrid(12, 16, ">");
			MainMenu.setGrid(12, 18, " ");
		}
		else if (cursorPosition == 1) // Curseur sur Quitter
		{
			MainMenu.setGrid(12, 16, " ");
			MainMenu.setGrid(12, 18, ">");
		}
		// -----------------------------------------

		MainMenu.refresh(); // Rafraichit la fenêtre
	}
	// --------------------------


	// ----- Boucle principale du jeu -----
	while (1)
	{

		break;
	}
	// ------------------------------------
}
// --------------------
