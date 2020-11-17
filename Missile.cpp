#include "Missile.h"

// ----- Constructeur/Destructeur -----
Missile::Missile(int x, int y, char axis, bool direction, int damages) : Projectile(x, y, 1, "m", axis, direction, 1, damages) {}

Missile::~Missile() {}
// ------------------------------------
