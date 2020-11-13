#include "Enemy.h"

// ----- Constructeur/Destructeur -----
Enemy::Enemy(int x, int y, std::string name, float speed) : Destructible(x, y, 100, "e"), m_name(name), m_speed(speed) {}

Enemy::~Enemy() {}
// ------------------------------------


void Enemy::Tick(float deltaTime)
{
	// Let's move towards the player to shoot him / bump him
}
