#include "Game.h"
#include "Vector2D.h"
#include <iostream>
using namespace std;

void Game::initWindow() 
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Kernmodule", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->lostGame = false;
	this->wonGame = false;
}

void Game::initTextures()
{
	//this->textures["Projectile"] = new sf::Texture();
	//this->textures["Projectile"]->loadFromFile("Resources/Images/arrow.png");
}

void Game::initGUI()
{
	//load fonts and init score
	if (!this->font.loadFromFile("Fonts/LemonDays.ttf")) { cout << "Didn't load" << "\n"; }

	//added sound for eating the enemy.
	this->buffer.loadFromFile("Sound/Nom.wav");
	this->eating.setBuffer(buffer);
	

	this->score.setFont(this->font);
	this->score.setCharacterSize(24);
	this->score.setFillColor(sf::Color::White);
	this->pointsScored = 0;
	this->amount = 1;
	this->score.setString(to_string(pointsScored));


	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);


	this->gameWinText.setFont(this->font);
	this->gameWinText.setCharacterSize(60);
	this->gameWinText.setFillColor(sf::Color::Green);
	this->gameWinText.setString("Good Going!");
	this->gameWinText.setPosition(
		this->window->getSize().x / 2.f - this->gameWinText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameWinText.getGlobalBounds().height / 2.f);
}

void Game::initPlayer()
{
	this->player = new ThePlayer();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 20.f;
	this->spawnTimer = this->spawnTimerMax;
}


Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}

	for (auto* i : this->enemies)
	{
		delete i;
	}

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(1.f, 0.f);
	// Had up down in there as well for the longest time until I realised it wasn't nessecary.
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->player->move(0.f, 1.f);*/
}


void Game::updateEnemies()
{
	//Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 80.f, -100.f, rand()% 20 + 20));
		this->spawnTimer = 0.f;
	}

	this->checkCollision();

	//cout << this->enemies.size() << endl;
}

void Game::checkCollision()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		Enemy* enemy = this->enemies.at(i);

		enemy->update(this->dt);

		//hope the getSize isn't a problem otherwise I would have just put 800 here.
		if (enemy->getPos().y > this->window->getSize().y)
		{
			delete this->enemies.at(i);
			this->enemies.erase(this->enemies.begin() + i);
			updateGUI(-this->amount);
		}

		Vector2D circleDistance;

		circleDistance.x = abs((enemy->getPos().x + enemy->getBounds()) - (this->player->getPos().x + this->player->getBounds().x / 2));
		circleDistance.y = abs((enemy->getPos().y + enemy->getBounds()) - (this->player->getPos().y + this->player->getBounds().y / 2));

		if (circleDistance.x > (this->player->getBounds().x / 2 + enemy->getBounds())) { continue; }
		if (circleDistance.y > (this->player->getBounds().y / 2 + enemy->getBounds())) { continue; }

		//probably won't happen but this checks if the circle is completely on top of the player. also erases it in case it does happen.
		if (circleDistance.x <= (this->player->getBounds().x / 2))
		{
			delete this->enemies.at(i);
			this->enemies.erase(this->enemies.begin() + i);
			updateGUI(this->amount);
			eating.play();
			continue;
		}
		if (circleDistance.y <= (this->player->getBounds().y / 2))
		{
			delete this->enemies.at(i);
			this->enemies.erase(this->enemies.begin() + i);
			updateGUI(this->amount);
			eating.play();
			continue;
		}

		//Doesn't like being squared, so just do it the long way.
		float cornerDistance_sq = (circleDistance.x - this->player->getBounds().x / 2) * (circleDistance.x - this->player->getBounds().x / 2) +
			(circleDistance.y - this->player->getBounds().y / 2) * (circleDistance.y - this->player->getBounds().y / 2);


		//we checking if anything is colliding with each other. if so erase em.
		if (cornerDistance_sq <= (enemy->getBounds() * enemy->getBounds()))
		{
			delete this->enemies.at(i);
			this->enemies.erase(this->enemies.begin() + i);
			eating.play();
			updateGUI(this->amount);
		}
	}
}

//deltatime for acceleration of the player.
void Game::updateDT() 
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateGUI(int amount)
{
	this->pointsScored += amount;
	this->score.setString(to_string(pointsScored));
}

void Game::update()
{
	this->updatePollEvents();
	if (this->pointsScored >= 10) wonGame = true;
	if (this->pointsScored <= -10) lostGame = true;

	if (!wonGame && !lostGame)
	{
		this->updateDT();
		this->updateInput();
		this->updateEnemies();
		this->player->update(this->dt);
	}
}

void Game::renderGUI()
{
	this->window->draw(score);
}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	if (wonGame)this->window->draw(this->gameWinText);
	if (lostGame)this->window->draw(this->gameOverText);

	this->renderGUI();
	this->window->display();
}
