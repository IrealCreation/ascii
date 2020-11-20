#include "Comet.h"
	

// ----- Constructeur/Destructeur -----
Comet::Comet(int x, int y, char axis, bool direction, float speed) : Projectile(x, y, 10, "C", axis, direction, speed, 10) {}

Comet::~Comet() {}
// ------------------------------------
