#include "Enemy.h"
#include <iostream>
using namespace std;
void Enemy::initShape()
{

}

void Enemy::initVariables()
{
	this->speedX = rand() % 5000 + 2000;
	this->speedY = rand() % 5000 + 2000;
	this->acceleration.y = 1.0f;
	this->acceleration.x = 0.f;
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	

}

Enemy::Enemy(float pos_x, float pos_y, float radius)
{
	this->initVariables();
	this->initShape();
	this->position.x = pos_x;
	this->position.y = pos_y;

	this->radius = radius;
	this->shape.setPosition(position.x, position.y);
	this->shape.setRadius(radius);
}

Enemy::~Enemy()
{

}

//Accessors
const float Enemy::getBounds() const
{
	return radius;
}

const Vector2D Enemy::getPos() const
{
	Vector2D result;
	result.x = position.x;
	result.y = position.y;
	return result;
}

//Functions
void Enemy::update(float counter)
{
	acceleration.y = 1.f;
	acceleration.x = 1.2f;
	acceleration.x *= speedX;
	acceleration.y *= speedY;

	acceleration += velocity * -5.0f;

	velocity += acceleration * counter;
	position += velocity * counter + acceleration * 0.5f * counter * counter;

	this->shape.setPosition(position.x, position.y);
	if (position.x > 800 - radius * 2) 
	{
		position.x = 800 - radius * 2;
		speedX *= -1;
		velocity.x *= -1;
		acceleration.x *= -1;
	}
	if (position.x < 0) 
	{
		position.x = 0;
		speedX *= -1;
		velocity.x *= -1;
		acceleration.x *= -1;
	}  
	acceleration.y = 0.f;
	acceleration.x = 0.f;
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
