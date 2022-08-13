#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Vector2D.h"

class ThePlayer
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	float width;
	float height;

	float speed;
	float counter;

	float attackCooldown;
	float attackCooldownMax;

	Vector2D bounds;
	Vector2D velocity;
	Vector2D acceleration;

	void initTexture();
	void initVariables();
	void initSprite();

public:
	ThePlayer();
	virtual ~ThePlayer();

	Vector2D getPos();
	Vector2D getBounds();
	Vector2D position;

	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAttack();
	void updateMovement();
	
	void deltaTime(float deltaTime);
	void update(float deltaTime);
	void render(sf::RenderTarget& target);
};

