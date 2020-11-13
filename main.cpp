#include <iostream>

#include "Character.h"
#include "Comet.h"
#include "Enemy.h"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	Comet comet(10, 10, "x", true, 1);
	std::cout << "Hey, I just saw a comet pass! It was beautiful." << std::endl;

	Enemy enemy(5, 5, "Tie Fighter", 1);
	std::cout << "That guy over there look suspect... You should avoid him." << std::endl;

	return 0;
}
