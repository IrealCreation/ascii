#include "GameLogic.h"




// _getch() pour récupérer les inputs du joueur

// ----- Constructeurs -----
GameLogic::GameLogic() : m_mapSizeX(50), m_mapSizeY(50), m_timingMs(50), m_timingS(m_timingMs / 1000.00)
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
	wcscpy_s(cfi.FaceName, L"Verdana"); // Choose your font ---- wcscpy_s used insted of std::wcscpy -----
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
	bool startGame = false;
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
				
				startGame = true; // À améliorer ?
				break;
			}
			else if (cursorPosition == 1)
			{
				// QUIT GAME
				
				startGame = false; // À améliorer ?
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

		MainMenu.refresh(); // Rafraîchit la fenêtre

		// ----- Début de la partie -----
		if (startGame == true)
		{
			// Instantiate the player character
			m_mainCharacter = new Character(10, 10);
			
			break;
			// START NEW GAME
		}
		// ------------------------------

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

// ----- Début du jeu/création de la fenêtre principale -----
// Layout MainScreen();
// ----------------------------------------------------------

void GameLogic::setMap(Layout &Screen) // Définit les dimensions X et Y de la map du jeu.
{
	m_mapSizeX = Screen.get_sizeX() + 10;
	m_mapSizeY = Screen.get_sizeY() + 10;
}

void GameLogic::addActor(Actor &element)
{
	m_spawnedActors.push_back(&element); // Ajoute un élément dans le tableau des actors
}

void GameLogic::removeActor(int actorId)
{
	// if spwnActor size != de 0 ----- ID 0 = Joueur.
	// Is it necessary to keep the player Character in the actor vector? After all it should not be deleted, doesn't tick, and isn't affected by scrolling...
	if (actorId != 0)
	{
		(*m_spawnedActors.at(actorId)).~Actor();
		m_spawnedActors.erase(m_spawnedActors.begin() + actorId); // Efface la case ciblée dans le tableau.
		m_spawnedActors.shrink_to_fit(); // Redimensionne le tableau.
	}
}

void GameLogic::setActorPositionOnScreen(int actorId, Layout &Screen)
{
	int x, y, color;
	std::string visualAspect;

	x = (*m_spawnedActors.at(actorId)).getPositionX();
	y = (*m_spawnedActors.at(actorId)).getPositionY();
	visualAspect = (*m_spawnedActors.at(actorId)).getVisualAspect();
	color = (*m_spawnedActors.at(actorId)).getColor();

	Screen.setGrid(x, y, visualAspect, color); // Positionner l'élément sur la grille de l'écran principal

}
//m_actors = new vector

void GameLogic::scrolling()
{
	// ----- Scrolling en Y -----
	for (int i(1), y(0); i < m_spawnedActors.size(); i++) // Pour chaque élément du tableau.
	{
		y = (*m_spawnedActors.at(i)).getPositionY(); // Récupère la position y de l'élément.
		
		(*m_spawnedActors.at(i)).setPositionY(1); // Déplace l'élément en y.
//		m_spawnedActors.at(i).setPositionY(-1);
		
		if (y <= 0 || y >= m_mapSizeY) // Si l'actor est en dehors de la map.
		{
			removeActor(i); // Alors supprime l'actor.
		}

	}
	// --------------------------
}

Character* GameLogic::getCharacter()
{
	return m_mainCharacter;
}


// ----- Spawn -----
/// On crée un vector dans lequel on enregistre chaque actor de la map
/// vector<type> NOM (TAILLE);
/// ==================================
/// == Display de l'actor à l'écran ==
/// == pour chaque élément          ==
/// ==================================
/// 
/// for (int i = 0; i < vector.getLength(); i++)
/// {
///		int x, y;
///		std::string actorLetter;
///		x = vector{i}.getPositionX;
///		y = vector{i}.getPositionY;
///		actorLetter = vector{i}.getVisualAspect;
///		Layout.setGrid(x, y, actorLetter);		
/// }
/// Layout.refresh();
// -----------------

// ----- Scrolling de la map -----
/// Scroll y
/// 
/// Scroll x
// -------------------------------




// ------------------------------
/// 1- inputs?
/// 2- actor's actions? (fonction tick pour chaque acteur)
/// 3- screen refresh
/// 
/// 
/// std::this_thread::sleep_for(std::chrono::milliseconds(timingMs));
/// 
// ------------------------------