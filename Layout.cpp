#include "Layout.h"


// ----- Constructeurs -----
Layout::Layout() : m_grid(0), m_gridUpdate(0)  // Met le pointeur à 0.
{
    Layout::initGrid(); // Initialise la grille.
}

Layout::Layout(int sizeX, int sizeY, int paddingX, int paddingY) : m_sizeX(sizeX), m_sizeY(sizeY), m_paddingX(paddingX), m_paddingY(paddingY), m_grid(0), m_gridUpdate(0)  // Met le pointeur à 0.
{
    Layout::initGrid(); // Initialise la grille
    
}

Layout::Layout(int sizeX, int sizeY, int paddingX, int paddingY, Layout &layout, std::string relativePosition) : m_sizeX(sizeX), m_sizeY(sizeY), m_grid(0), m_gridUpdate(0)  // Met le pointeur à 0.
{
    if (relativePosition == "X" || relativePosition == "x")
    {
        m_paddingX += (layout.get_paddingX() + layout.get_sizeX() + 2) + paddingX;
        m_paddingY += layout.get_paddingY() + paddingY;
        Layout::initGrid(); // Initialise la grille avec un padding relatif sur X
    }
    else if (relativePosition == "Y" || relativePosition == "y")
    {
        m_paddingX += layout.get_paddingX() + paddingX;
        m_paddingY += (layout.get_paddingY() + layout.get_sizeY() + 2) + paddingY;
        Layout::initGrid(); // Initialise la grille avec un padding relatif sur Y
    }
    else
    {
        m_paddingX = paddingX;
        m_paddingY = paddingY;
        Layout::initGrid(); // Initialise sans padding relatif
    }
}
// -------------------------


// ----- Destructeur -----
Layout::~Layout()
{
    // Détruit les pointeurs pour empêcher une fuite de mémoire.
    delete[] m_grid; 
    delete[] m_gridUpdate;
    delete[] m_gridColors;
}
// -----------------------



// ----- Initialisation de la grille -----
void Layout::initGrid()
{
    // ----- Ligne nécessaire pour changer les couleurs -----
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // ------------------------------------------------------

    m_indexTotal = (m_sizeX * m_sizeY);
    m_grid = new std::string[m_indexTotal];
    m_gridUpdate = new std::string[m_indexTotal];
    m_gridColors = new int[m_indexTotal];

    // ----- Initialisation des nouvelles variables -----
    for (int i = 0; i < m_indexTotal; i++)
    {
        m_grid[i] = " ";
        m_gridUpdate[i] = " ";
        m_gridColors[i] = 7;
    }
    // --------------------------------------------------

    // ----- Cache le curseur -----
    Layout::ShowConsoleCursor(false);
    // ----------------------------

}
// ---------------------------------------



// ----- Récupère les informations -----
int Layout::get_x_location(int index)
{
    int x = index % m_sizeX;
    return x;
}

int Layout::get_y_location(int index)
{
    int y = index / m_sizeX;
    return y;
}

int Layout::get_index(int x, int y)
{
    int index;
    index = (y * m_sizeX) + x; 
    return index;
}

int Layout::get_paddingX() { return m_paddingX; }

int Layout::get_paddingY() { return m_paddingY; }

int Layout::get_sizeX() { return m_sizeX; }

int Layout::get_sizeY() { return m_sizeY; }
// -------------------------------------


// ----- Définir un élément de la grille -----
void Layout::setGrid(int x, int y, std::string text)
{
    int index = get_index(x, y), length = text.length();

    for (int i = 0; i < length; i++)
    {
        m_gridUpdate[index] = text[i];
        m_gridColors[index] = 7;
        index++;
    }
}
// -------------------------------------------

// ----- Définir un élément de la grille avec choix de la couleur -----
void Layout::setGrid(int x, int y, std::string text, int color)
{
    int index = get_index(x, y), length = text.length();
    
    for (int i = 0; i < length; i++)
    {
        m_gridUpdate[index] = text[i];
        m_gridColors[index] = color;
        index++;
    }
}
// --------------------------------------------------------------------


// ----- Création d'une bordure -----
void Layout::createBorders(std::string borderCharacter)
{
    int x, y, xM(-1), yM(-1); // <- Variables mémoires de x et y
    for (int i = 0; i < m_indexTotal; i++)
    {
        y = get_y_location(i);
        if (y != yM) // On vérifie que le caractère n'a pas déjà été affiché.
        {
            setCursorPosition(-1, y);
            std::cout << borderCharacter;
            setCursorPosition(m_sizeX, y);
            std::cout << borderCharacter;
            yM = y;
        }
    }
    for (int i = 0; i < m_indexTotal; i++)
    {
        x = get_x_location(i);
        if (x != xM) // On vérifie que le caractère n'a pas déjà été affiché.
        {
            setCursorPosition(x, -1);
            std::cout << borderCharacter;
            setCursorPosition(x, m_sizeY);
            std::cout << borderCharacter;
            xM = x;
        }
    }
}
// ----------------------------------

// ----- Visibilité du layout -----
void Layout::setVisibility(bool isVisible, std::string borders)
{
    int x, y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    createBorders(borders);

    if (isVisible == true)
    {
        for (int i = 0; i < m_indexTotal; i++)
        {            
            x = get_x_location(i);
            y = get_y_location(i);
            setCursorPosition(x, y);
            SetConsoleTextAttribute(hConsole, m_gridColors[i]);
            std::cout << m_gridUpdate[i];
            SetConsoleTextAttribute(hConsole, 7);
        }        
    }
    else if (isVisible == false)
    {
        for (int i = 0; i < m_indexTotal; i++)
        {
            if (m_gridUpdate[i] == " ") {continue;}
            x = get_x_location(i);
            y = get_y_location(i);
            setCursorPosition(x, y);
            SetConsoleTextAttribute(hConsole, m_gridColors[i]);
            std::cout << " ";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }    
}
// --------------------------------


// ----- Poisitionne le curseur pour réécriture -----
// x is the column, y is the row. The origin (0,0) is top-left.
void Layout::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)(x + m_paddingX + 1), (SHORT)(y + m_paddingY + 1) };
    SetConsoleCursorPosition(hOut, coord);
}
// --------------------------------------------------



// ----- Cache le curseur underscore dans la console -----
void Layout::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
// -------------------------------------------------------



// ----- Met à jour et affiche la grille -----
void Layout::refresh()
{
    int x, y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < m_indexTotal; i++)
    {
        if (m_gridUpdate[i] == m_grid[i])
        {
            continue;
        }
               
        x = Layout::get_x_location(i);
        y = Layout::get_y_location(i);
        setCursorPosition(x, y);
        SetConsoleTextAttribute(hConsole, m_gridColors[i]);
        std::cout << m_gridUpdate[i];
        SetConsoleTextAttribute(hConsole, 7);
    }
    for (int i = 0; i < m_indexTotal; i++)
    {
        m_grid[i] = m_gridUpdate[i];
    }
}
// -------------------------------