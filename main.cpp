#include <iostream>

#include "Comet.h"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	Comet comet(0, 0, "x", true, 1);
	std::cout << "Hey, I just saw a comet pass! It was beautiful." << std::endl;

	return 0;
}
