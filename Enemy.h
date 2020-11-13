#pragma once
#include "Destructible.h"

class Enemy : public Destructible
{
public:
	// ----- Constructeur/Destructeur -----
	Enemy(int x, int y, std::string name, float speed);

	~Enemy();
	// ------------------------------------

	void tick(float deltaTime);

protected:
	std::string m_name;
	
	float m_speed;

	float m_moveRemaining = 0;
};

