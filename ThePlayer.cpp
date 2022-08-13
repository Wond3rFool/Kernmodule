#include<chrono>
#include<SFML/Graphics.hpp>


#include "ThePlayer.h"


void ThePlayer::initTexture()
{
	this->texture.loadFromFile("Resources/Images/big_demon.png");
}

void ThePlayer::initVariables()
{
	this->counter;
	this->acceleration.x = 0.f;
	this->acceleration.y = 0.f;
	
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	
	this->position.x = 400;
	this->position.y = 500;

	this->width = 64.0f;
	this->height = 72.0f;

	this->bounds.x = width;
	this->bounds.y = height;

	this->speed = 4444.0f;

	this->attackCooldown = attackCooldownMax;
	this->attackCooldownMax = 10.f;
}

void ThePlayer::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(position.x, position.y);
	this->sprite.setScale(2.f, 2.f);
}

ThePlayer::ThePlayer()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

ThePlayer::~ThePlayer()
{
}

Vector2D ThePlayer::getPos()
{
	return position;
}

Vector2D ThePlayer::getBounds()
{
	return bounds;
}

void ThePlayer::move(const float dirX, const float dirY)
{
	acceleration.x = dirX;
	acceleration.y = dirY;
}

const bool ThePlayer::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) 
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void ThePlayer::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void ThePlayer::updateMovement()
{
	acceleration *= speed;

	acceleration += velocity * -5.0f;

	if (acceleration.x != 0.0f && acceleration.y != 0.0f) 
	{
		acceleration *= 0.707f;
	}

	velocity += acceleration * counter;
	position += velocity * counter + acceleration * 0.5f * counter * counter;
	
	if (position.x >= 800 - width) position.x = 800 - width;
	if (position.x <= 0) position.x = 0;

	sprite.setPosition(position.x, position.y);
	
	acceleration.x = 0.f;
	acceleration.y = 0.f;
}

void ThePlayer::deltaTime(float deltaTime)
{
	counter = deltaTime;
}

void ThePlayer::update(float deltaTime)
{
	this->deltaTime(deltaTime);
	this->updateAttack();
	this->updateMovement();
}

void ThePlayer::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


