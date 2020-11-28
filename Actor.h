#pragma once

// ----- Headers -----
#include <string>
// -------------------


/// <summary>
///	Abstract class inherited by every game object appearing in the map
/// </summary>
class Actor
{
public:
	// ----- Constructeur/Destructeur -----

	Actor(int x, int y, std::string visualAspect);
	Actor(int x, int y, std::string visualAspect, int color);

	~Actor();
	// ------------------------------------

  
  // ----- Get -----
	int getPositionX();
	int getPositionY();
	std::string getVisualAspect();
	int getColor();
	// ---------------
  
  // ----- Set -----
	void setPosition(int x, int y);
	void setPositionX(int x);
	void setPositionY(int y);
  // ---------------

	// ----- Méthodes -----
	/// <summary>
	/// Move the actor to the specified coordinates
	/// </summary>
	/// <param name="x">X coordinate</param>
	/// <param name="y">Y coordinate</param>
	/// <returns>True if the move could be done, false otherwise</returns>
	virtual bool moveTo(int x, int y);

	/// <summary>
	/// tick should be called at each game update
	/// </summary>
	/// <param name="deltaTime">Time since last game update in seconds</param>
	virtual void tick(float deltaTime) = 0;

	/// <summary>
	/// What happens when I collide with another actor?
	/// </summary>
	/// <param name="collider">The actor I collide with</param>
	virtual void collideWith(Actor* collider);

	bool getCollision();

	int getCollisionDamages();
  
	// --------------------

protected:
	// ----- Attributs -----
	int m_positionX;
	int m_positionY;

	/// <summary>
	/// How the actor is visually rendered
	/// </summary>
	std::string m_visualAspect = "/";

	/// <summary>
	/// The color in which the actor is visually rendered
	/// </summary>
	int m_color = 7;

	/// <summary>
	/// Do I trigger collision when someone tries to enter my tile (true), or do I simply disappear (false)? 
	/// </summary>
	bool m_collision = true;

	/// <summary>
	/// How much damages I inflict when someone collides me?
	/// </summary>
	int m_collisionDamages = 0;
	// ---------------------

};
