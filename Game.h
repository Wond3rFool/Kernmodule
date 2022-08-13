#pragma once
#include <map>
#include "ThePlayer.h"
#include"Enemy.h"
#include <SFML/Audio.hpp>

class Game
{

private:
	sf::RenderWindow* window;

	//DeltaTime
	sf::Clock dtClock;
	float dt;

	//resources
	std::map<std::string, sf::Texture*> textures;
	
	//player
	ThePlayer* player;

	//GUI
	sf::Font font;
	sf::Text score;
	sf::Text gameOverText;
	sf::Text gameWinText;

	sf::SoundBuffer buffer;
	sf::Sound eating;

	int pointsScored;
	int amount;
	bool lostGame;
	bool wonGame;


	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;


	//private functions
	void initWindow();
	void initTextures();
	void initGUI();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	void run();

	void updateDT();
	void updatePollEvents();
	void updateGUI(int amount);
	void checkCollision();
	void updateEnemies();
	void updateInput();
	void update();
	void renderGUI();
	void render();
};

