#include "GameLogic.h"




// _getch() pour récupérer les inputs du joueur

// ----- Constructeurs -----
GameLogic::GameLogic() : m_mapSizeX(55), m_mapSizeY(55), m_hiddenPart(20), m_timingMs(50), m_timingS(m_timingMs / 1000.00)
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
			break;
			// START NEW GAME
		}
		// ------------------------------

	}

	MainMenu.setVisibility(false, " "); // Menu principal rendu invisible.
	// --------------------------

	// ----- Création de la fenêtre principale -----
	m_spawnedActors.push_back(new Character((m_mapSizeX / 2), (m_mapSizeY / 2), 100)); // Création du personnage principal au centre de l'écran
	m_spawnedActors.push_back(new Comet(45, 15, "x", 1, 1)); // Création d'une comète
	m_spawnedActors.push_back(new Comet(27, 18, "y", 1, 1)); // Création d'une comète
	m_spawnedActors.push_back(new Comet(50, 16, "x", 1, 2)); // Création d'une comète

	Layout MainScreen((m_mapSizeX - m_hiddenPart), (m_mapSizeY - m_hiddenPart), 1, 1);
	MainScreen.createBorders("#");
	setActorPositionOnScreen(0, MainScreen);
	setActorPositionOnScreen(1, MainScreen);
	MainScreen.refresh();




	for (int j = 0; j < 50; j++)
	{
		// ----- Efface l'ancienne position des acteurs -----
		removeAllActorsFromScreen(MainScreen);
		// --------------------------------------------------

		for (int i = 0; i < m_spawnedActors.size(); i++) // Pour chaque acteur présent.
		{
			(*m_spawnedActors.at(i)).tick(m_timingS); // Lance le tick de chaque acteur.

			if ((*m_spawnedActors.at(i)).getPositionX() < 0 || (*m_spawnedActors.at(i)).getPositionX() > m_mapSizeX
				|| (*m_spawnedActors.at(i)).getPositionY() < 0 || (*m_spawnedActors.at(i)).getPositionY() > m_mapSizeY) // Si l'acteur sort de la map.
			{
				removeActor(i); // Supprime l'acteur.
			}

		}

		for (int i = 0; i < m_spawnedActors.size(); i++) // Place chaque acteur sur l'écran.
		{
			setActorPositionOnScreen(i, MainScreen);
		}
		MainScreen.refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
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

// ----- Début du jeu/création de la fenêtre principale -----
// Layout MainScreen();
// ----------------------------------------------------------


// ----- Set map || Test only -----
void GameLogic::setMap(Layout &Screen) // Définit les dimensions X et Y de la map du jeu.
{
	m_mapSizeX = Screen.get_sizeX() + 10;
	m_mapSizeY = Screen.get_sizeY() + 10;
}
// --------------------------------

// ----- Add actor || Test only -----
void GameLogic::addActor(Actor &element)
{
	m_spawnedActors.push_back(&element); // Ajoute un élément dans le tableau des actors
}
// ----------------------------------


void GameLogic::removeActor(int actorId)
{
	// if spwnActor size != de 0 ----- ID 0 = Joueur.
	if (actorId != 0)
	{
		//(*m_spawnedActors.at(actorId)).~Actor();
		m_spawnedActors.erase(m_spawnedActors.begin() + actorId); // Efface la case ciblée dans le tableau.
		m_spawnedActors.shrink_to_fit(); // Redimensionne le tableau.
	}
}


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


void GameLogic::removeAllActorsFromScreen(Layout &Screen)
{
	int x = 0;
	int y = 0; 

	for (int i = 1; i < m_spawnedActors.size(); i++)
	{
		x = (*m_spawnedActors.at(i)).getPositionX();
		y = (*m_spawnedActors.at(i)).getPositionY();
		if (x < m_mapSizeX - (m_hiddenPart / 2) && x >= (m_hiddenPart / 2) && y < m_mapSizeY - (m_hiddenPart / 2) && y >= (m_hiddenPart / 2))
		{
			Screen.setGrid(getActorXPositionOnScreen(i, Screen), getActorYPositionOnScreen(i, Screen), " "); // Place un vide à chaque acteur (sauf joueur).
		}
	}
}




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
		Screen.setGrid(x - (m_hiddenPart / 2), y - (m_hiddenPart / 2), aspect, color); // Positionner l'élément sur la grille de l'écran principal
	}
}

void GameLogic::scrolling()
{
	// ----- Scrolling en Y -----
	for (int i(1), y(0); i < m_spawnedActors.size(); i++) // Pour chaque élément du tableau.
	{
		y = (*m_spawnedActors.at(i)).getPositionY(); // Récupère la position y de l'élément.
		
		(*m_spawnedActors.at(i)).setPositionY(((*m_spawnedActors.at(i)).getPositionY()) + 1); // Déplace l'élément vers le bas.
//		m_spawnedActors.at(i).setPositionY(((*m_spawnedActors.at(i)).getPositionY()) - 1); // Déplace l'élément vers le haut.
		
		if (y <= 0 || y >= m_mapSizeY) // Si l'actor est en dehors de la map.
		{
			removeActor(i); // Alors supprime l'actor.
		}

	}
	// --------------------------
} 

// ----- Spawn -----
void GameLogic::spawn()
{
	int x, y;
	int randomNb;

	// ----- Initialisation de l'aléatoire ----
	srand(time(NULL)); // Initialisation du seed de l'aléatoire.
	
	// -------------------------------------------

	// ----- Spawn des comètes sur les nouvelles cases crées en y -----
	for (int i = 0; i < m_mapSizeY; i++) // Pour chaque case en y.
	{
		randomNb = rand() % 100 + 1; // Nombre aléatoire entre 1 et 100.
		if (randomNb < 20 && isLocationEmpty(0, i) == true)
		{
			m_spawnedActors.push_back(new Comet(0, i, "y", 1, 1));
		}					
	}
	// ----------------------------------------------------------------	
}
// -----------------

// ----- Vérifie si un emplacement est vide -----
bool GameLogic::isLocationEmpty(int x, int y)
{
	bool output = 1; // Emplacement vide par défaut.
	int selectedX(x), selectedY(y); // Coordonnées x y qu'on souhaite vérifier.
	int actorX(0), actorY(0); // Coordonnées des acteurs.

	for (int i = 0; i < m_spawnedActors.size(); i++) // Vérification de la position de chaque acteur de la boucle.
	{
		actorX = (*m_spawnedActors.at(i)).getPositionX();
		actorY = (*m_spawnedActors.at(i)).getPositionY();
		if (actorX == selectedX && actorY == selectedY) // Si les coordonnées correspondent à celle d'un acteur
		{
			output = false; // alors l'emplacement n'est pas vide.
		}
	}

	return output;
}
// ----------------------------------------------


// ----- Récupère l'ID d'un acteur à partir de sa position x et y -----
// À lancer après avoir fait un isLocationEmpty
// sinon renvoie à Character (ID = 0).
int GameLogic::getActorIdByLocation(int x, int y) 
{
	int id(0);
	int actorX(0), actorY(0);

	for (int i = 0; i < m_spawnedActors.size(); i++) // Vérification de la position de chaque acteur de la boucle.
	{
		actorX = (*m_spawnedActors.at(i)).getPositionX();
		actorY = (*m_spawnedActors.at(i)).getPositionY();
		if (actorX == x && actorY == y) // Si les coordonnées correspondent à celle d'un acteur
		{
			id = i; // alors on récupère son ID.
		}
	}
	return id;
}
// --------------------------------------------------------------------

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
/// 
/// To spawn a new Actor do :
/// m_spawnedActors.push_back(new Actor());
/// 
/// - Check initial actors' positions
/// - Move actors
/// - Check new actors' positions
///3- make sure they are inside the screen and display actors on screen
// ------------------------------