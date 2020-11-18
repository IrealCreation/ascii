#include "GameLogic.h"




// _getch() pour r�cup�rer les inputs du joueur

// ----- Constructeurs -----
GameLogic::GameLogic() : m_mapSizeX(55), m_mapSizeY(55), m_hiddenPart(20), m_timingMs(50), m_timingS(m_timingMs / (float)1000.00)
{
	initialisation();
}
// -------------------------

// ----- Destructeur -----
GameLogic::~GameLogic(){}
// ------------------------


// ----- New Game -----
void GameLogic::newGame()
{

	// ----- Menu principal -----
	// ----- Cr�ation du Menu -----
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
		// ----- S�lection d'une action dans le menu principal -----
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
				
				startGame = true; // � am�liorer ?
				break;
			}
			else if (cursorPosition == 1)
			{
				// QUIT GAME
				
				startGame = false; // � am�liorer ?
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

		MainMenu.refresh(); // Rafra�chit la fen�tre


		// ----- D�but de la partie -----
		if (startGame == true)
		{
			break;
			// START NEW GAME
		}
		// ------------------------------

	}

	MainMenu.setVisibility(false, " "); // Menu principal rendu invisible.
	// --------------------------

	// ----- Cr�ation de la fen�tre principale -----
	spawn(new Character((m_mapSizeX / 2), (m_mapSizeY / 2), 100)); // Cr�ation du personnage principal au centre de l'�cran
	spawn(new Comet(30, 16, "x", 1, (float)1.7));


	Layout MainScreen((m_mapSizeX - m_hiddenPart), (m_mapSizeY - m_hiddenPart), 1, 1);
	MainScreen.createBorders("#");
	setActorPositionOnScreen(0, MainScreen);
	setActorPositionOnScreen(1, MainScreen);
	MainScreen.refresh();

	Layout SideScreen(20, 10, 5, 0, MainScreen, "X");
	SideScreen.setGrid(5, 0, "- Debug -");
	SideScreen.setGrid(5, 5, "Removed Actors:");

	std::string actorsAmount;
	int actorsRemoved = 0;

	for (int j = 0; j < 500; j++)
	{
		// ----- Efface l'ancienne position des acteurs -----
		removeAllActorsFromScreen(MainScreen);
		// --------------------------------------------------
	
		for (std::size_t i = 0; i < m_spawnedActors.size(); i++) // Pour chaque acteur pr�sent.
		{
			(*m_spawnedActors.at(i)).tick(m_timingS); // Lance le tick de chaque acteur.

			if ((*m_spawnedActors.at(i)).getPositionX() < 0 || (*m_spawnedActors.at(i)).getPositionX() > m_mapSizeX || (*m_spawnedActors.at(i)).getPositionY() < 0 || (*m_spawnedActors.at(i)).getPositionY() > m_mapSizeY) // Si l'acteur sort de la map.
			{
				removeActor(i); // Supprime l'acteur.
				actorsRemoved++;
				SideScreen.setGrid(5, 6, std::to_string(actorsRemoved));
				
			}

		}
		spawn();
		inputs();

		for (std::size_t i = 0; i < m_spawnedActors.size(); i++) // Place chaque acteur sur l'�cran.
		{
			setActorPositionOnScreen(i, MainScreen);
		}
		MainScreen.refresh();

		actorsAmount = std::to_string((int)m_spawnedActors.size());
		SideScreen.setGrid(5, 4, actorsAmount);
		SideScreen.refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds((long)m_timingMs));
	}
	
	// ---------------------------------------------

	// ----- Boucle principale du jeu -----
	while (1)
	{

		break;
	}
	// ------------------------------------
}
// --------------------



// ----- V�rifie si un emplacement est vide -----
bool GameLogic::isLocationEmpty(int x, int y)
{
	bool output = true; // Emplacement vide par d�faut.
	int selectedX(x), selectedY(y); // Coordonn�es x y qu'on souhaite v�rifier.
	int actorX(0), actorY(0); // Coordonn�es des acteurs.

	for (std::size_t i = 0; i < m_spawnedActors.size(); i++) // V�rification de la position de chaque acteur de la boucle.
	{
		actorX = (*m_spawnedActors.at(i)).getPositionX();
		actorY = (*m_spawnedActors.at(i)).getPositionY();
		if (actorX == selectedX && actorY == selectedY) // Si les coordonn�es correspondent � celle d'un acteur
		{
			output = false; // alors l'emplacement n'est pas vide.
		}
	}

	return output;
}
// ----------------------------------------------

// ----- Get Actor from list by location -----
Actor& GameLogic::getActor(int x, int y)
{
	int actorId = getActorIdByLocation(x, y);
	return (*m_spawnedActors.at(actorId));
}
// -------------------------------------------

// ----- Unspawn an actor by reference -----
void GameLogic::removeActor(Actor& actor)
{
	int x = actor.getPositionX(), y = actor.getPositionY();
	int ID = getActorIdByLocation(x, y);
	removeActor(ID);
}
// -----------------------------------------

// ----- Spawn for debug -----
void GameLogic::spawn(Actor *actor)
{
	m_spawnedActors.push_back(actor);
}
// ---------------------------

// ----- Initialisation -----
void GameLogic::initialisation()
{
	// ----- Gestion de la police d'�criture -----
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
// --------------------------


// ----- Inputs movements -----
void GameLogic::inputs()
{
	BlockInput(false);
	if (_kbhit()) // Check if a key is pressed.
	{
		switch (_getch())
		{
		case KEY_UP:
			for (std::size_t i = 1; i < m_spawnedActors.size(); i++)
			{
				(*m_spawnedActors.at(i)).setPositionY(((*m_spawnedActors.at(i)).getPositionY()) + 1);
			}
			break;
		case KEY_LEFT:
			for (std::size_t i = 1; i < m_spawnedActors.size(); i++)
			{
				(*m_spawnedActors.at(i)).setPositionX(((*m_spawnedActors.at(i)).getPositionX()) + 1);
			}
			break;
		case KEY_RIGHT:
			for (std::size_t i = 1; i < m_spawnedActors.size(); i++)
			{
				(*m_spawnedActors.at(i)).setPositionX(((*m_spawnedActors.at(i)).getPositionX()) - 1);
			}
			break;
		case KEY_DOWN:
			for (std::size_t i = 1; i < m_spawnedActors.size(); i++)
			{
				(*m_spawnedActors.at(i)).setPositionY(((*m_spawnedActors.at(i)).getPositionY()) - 1);
			}
			break;
		default:
			break;
		}
	}
	BlockInput(true);
}
// ----------------------------



// ----- Spawn -----
void GameLogic::spawn()
{
	int x(0), y(0);

	// ----- Utilisation de <random> -----
	int rangeFrom(1), rangeTo(4);

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<int> distr(rangeFrom, rangeTo); // define the range

	// -----------------------------------
	if ((m_spawnedActors.size()) < 20) 
	{
		if (distr(gen) == 1) // Spawn � gauche.
		{
			rangeFrom = 0;
			rangeTo = m_hiddenPart / 2;
			std::uniform_int_distribution<int> distrX(rangeFrom, rangeTo);
			x = distrX(gen);
			rangeFrom = 0;
			rangeTo = m_mapSizeY;
			std::uniform_int_distribution<int> distrY(rangeFrom, rangeTo);
			y = distrY(gen);

			if (isLocationEmpty(x, y) == true)
			{
				m_spawnedActors.push_back(new Comet(x, y, "x", 1, 10));
			}
		}
		else if (distr(gen) == 2) // Spawn � droite.
		{
			rangeFrom = m_mapSizeX - (m_hiddenPart / 2);
			rangeTo = m_mapSizeX;
			std::uniform_int_distribution<int> distrX(rangeFrom, rangeTo);
			x = distrX(gen);
			rangeFrom = 0;
			rangeTo = m_mapSizeY;
			std::uniform_int_distribution<int> distrY(rangeFrom, rangeTo);
			y = distrY(gen);
			if (isLocationEmpty(x, y) == true)
			{
				m_spawnedActors.push_back(new Comet(x, y, "x", 0, 1));
			}
		}
		else if (distr(gen) == 3) // Spawn en haut.
		{
			rangeFrom = 0;
			rangeTo = m_hiddenPart / 2;
			std::uniform_int_distribution<int> distrY(rangeFrom, rangeTo);
			y = distrY(gen);
			rangeFrom = 0;
			rangeTo = m_mapSizeX;
			std::uniform_int_distribution<int> distrX(rangeFrom, rangeTo);
			x = distrX(gen);
			if (isLocationEmpty(x, y) == true)
			{
				m_spawnedActors.push_back(new Comet(x, y, "y", 1, 1));
			}
		}
		else if (distr(gen) == 4) // Spawn en bas.
		{
			rangeFrom = m_mapSizeY - (m_hiddenPart / 2);
			rangeTo = m_mapSizeY;
			std::uniform_int_distribution<int> distrY(rangeFrom, rangeTo);
			y = distrY(gen);
			rangeFrom = 0;
			rangeTo = m_mapSizeX;
			std::uniform_int_distribution<int> distrX(rangeFrom, rangeTo);
			x = distrX(gen);
			if (isLocationEmpty(x, y) == true)
			{
				m_spawnedActors.push_back(new Comet(x, y, "y", 0, 1));
			}
		}
	}
}
// ----------------- 

// ----- Unspawn an actor -----
void GameLogic::removeActor(int actorId)
{
	if (actorId != 0)
	{
		m_spawnedActors.erase(m_spawnedActors.begin() + actorId); // Efface la case cibl�e dans le tableau.
	}
}
// ----------------------------



// ----- Get actors' positions on screen -----
int GameLogic::getActorXPositionOnScreen(int actorId, Layout& Screen)
{
	int x = (*m_spawnedActors.at(actorId)).getPositionX() - (m_hiddenPart / 2);
	return x;
}
int GameLogic::getActorYPositionOnScreen(int actorId, Layout& Screen)
{
	int y = (*m_spawnedActors.at(actorId)).getPositionY() - (m_hiddenPart / 2);
	return y;
}
// -------------------------------------------

// ----- Remove the visual display of all actors / Used to refresh the screen -----
void GameLogic::removeAllActorsFromScreen(Layout &Screen)
{
	int x = 0;
	int y = 0; 

	for (std::size_t i = 1; i < m_spawnedActors.size(); i++)
	{
		x = (*m_spawnedActors.at(i)).getPositionX();
		y = (*m_spawnedActors.at(i)).getPositionY();
		if (x < m_mapSizeX - (m_hiddenPart / 2) && x >= (m_hiddenPart / 2) && y < m_mapSizeY - (m_hiddenPart / 2) && y >= (m_hiddenPart / 2))
		{
			Screen.setGrid(getActorXPositionOnScreen(i, Screen), getActorYPositionOnScreen(i, Screen), " "); // Place un vide � chaque acteur (sauf joueur).
		}
	}
}
// --------------------------------------------------------------------------------

// ----- Translate actors' locations on map to screen location -----
void GameLogic::setActorPositionOnScreen(int actorId, Layout &Screen)
{	
	int x(7), y(5), color(2);
	std::string aspect = "v";

	x = (*m_spawnedActors.at(actorId)).getPositionX();
	y = (*m_spawnedActors.at(actorId)).getPositionY();
	color = (*m_spawnedActors.at(actorId)).getColor();
	aspect = (*m_spawnedActors.at(actorId)).getVisualAspect();

	if (x < m_mapSizeX - (m_hiddenPart / 2) && x >= (m_hiddenPart / 2) && y < m_mapSizeY - (m_hiddenPart / 2) && y >= (m_hiddenPart / 2))
	{
		Screen.setGrid(x - (m_hiddenPart / 2), y - (m_hiddenPart / 2), aspect, color); // Positionner l'�l�ment sur la grille de l'�cran principal
	}
}
// -----------------------------------------------------------------



// ----- R�cup�re l'ID d'un acteur � partir de sa position x et y -----
// � lancer apr�s avoir fait un isLocationEmpty
// sinon renvoie � Character (ID = 0).
int GameLogic::getActorIdByLocation(int x, int y) 
{
	int id(0);
	int actorX(0), actorY(0);

	for (std::size_t i = 0; i < m_spawnedActors.size(); i++) // V�rification de la position de chaque acteur de la boucle.
	{
		actorX = (*m_spawnedActors.at(i)).getPositionX();
		actorY = (*m_spawnedActors.at(i)).getPositionY();
		if (actorX == x && actorY == y) // Si les coordonn�es correspondent � celle d'un acteur
		{
			id = i; // alors on r�cup�re son ID.
		}
	}
	return id;
}
// --------------------------------------------------------------------

// ----- Get Actor from list by ID -----
Actor& GameLogic::getActor(int actorId)
{
	return (*m_spawnedActors.at(actorId));
}
// -------------------------------------



// ------------------------------
/// 1- inputs?
/// 2- actor's actions? (fonction tick pour chaque acteur)
/// 3- screen refresh
/// 
/// 
/// std::this_thread::sleep_for(std::chrono::milliseconds(timingMs));
/// 
/// 
/// To spawn a new Actor do :
/// m_spawnedActors.push_back(new Actor());
/// 
/// - Check initial actors' positions
/// - Move actors
/// - Check new actors' positions
/// - make sure they are inside the screen and display actors on screen
// ------------------------------
// ----- TO DO -----
/// - Player's speed
// -----------------