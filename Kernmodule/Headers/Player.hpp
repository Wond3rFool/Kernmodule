#pragma once
class Player
{
	short x;

	unsigned short y;

	sf::Sprite sprite;

	sf::Texture texture;

public:
	Player();

	void draw(sf::RenderWindow& i_window);

};

