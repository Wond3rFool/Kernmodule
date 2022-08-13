#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Graphics.hpp>
#include "Vector2D.h"

class Enemy 
{
private:

	sf::CircleShape shape;

	float speedX;
	float speedY;
	float radius;
	int pointCount;

	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;

	void initVariables();
	void initShape();


public:

	Enemy(float pos_x, float pos_y, float radius);
	virtual ~Enemy();

	//Accessors
	const Vector2D getPos() const;
	const float getBounds() const;

	//Functions
	void update(float counter);
	void render(sf::RenderTarget* target);
};
#endif //!ENEMY_H