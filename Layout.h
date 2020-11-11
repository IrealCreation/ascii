#pragma once

// ----- Headers -----
#include <string>
#include <iostream>

#include <Windows.h>
// -------------------


class Layout
{
public:
	Layout();
	Layout(int sizeX, int sizeY, int paddingX, int paddingY);
	Layout(int sizeX, int sizeY, int paddingX, int paddingY, Layout &layout, std::string relativePosition);
	~Layout();


	void setGrid(int x, int y, std::string text);// <- Définir un élément dans la grille en position [x ; y]
	void setGrid(int x, int y, std::string text, int color);// <- Définir un élément dans la grille en position [x ; y] et choisir sa couleur
	void createBorders(std::string borderCharacter);
	void setVisibility(bool isVisible, std::string borders);

	void refresh();


private:
	void initGrid(); // Appelé dans le constructeur.

	int get_x_location(int index);
	int get_y_location(int index);
	int get_index(int x, int y);

	int get_paddingX();
	int get_paddingY();
	int get_sizeX();
	int get_sizeY();


	void setCursorPosition(int x, int y);
	void ShowConsoleCursor(bool showFlag);

	// ----- Attributs -----
	int m_sizeX = 80;
	int m_sizeY = 40;
	int m_indexTotal;

	int m_paddingX = 0;
	int m_paddingY = 0;

	std::string* m_grid; // <- Actuelle grille de l'écran
	std::string* m_gridUpdate; // <- Modifications apportées à la grille avant le refresh

	int* m_gridColors; // <- Stocke la couleur des éléments de la grille 
	// ---------------------
};

