#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "resources.h"
#include "bullets.h"
#include "players.h"
#include "enemy.h"
#include "Menu.h"
#include "AboutMe.h"
using namespace std;
using namespace sf;

//Sterowanie Graczem 1
void playerMovement(Player& player, RenderWindow& window) {
	if (Keyboard::isKeyPressed(Keyboard::W))
		player.shape.move(0.f, -8.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		player.shape.move(0.f, 8.f);
	if (Keyboard::isKeyPressed(Keyboard::A))
		player.shape.move(-8.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		player.shape.move(8.f, 0.f);

	//Sprawdzenie czy Gracz 1 wychodzi poza ekran, jeœli tak to ustawia go przy krawêdzi 
	if (player.shape.getPosition().x <= 0)
		player.shape.setPosition(0.f, player.shape.getPosition().y);
	if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width)
		player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
	if (player.shape.getPosition().y <= 0)
		player.shape.setPosition(player.shape.getPosition().x, 0.f);
	if (player.shape.getPosition().y >= window.getSize().y - player.shape.getGlobalBounds().height)
		player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height);
}

//Sterowanie Graczem 2
void player2Movement(Player2& player2, RenderWindow& window) {

	if (Keyboard::isKeyPressed(Keyboard::I))
		player2.shape.move(0.f, -8.f);
	if (Keyboard::isKeyPressed(Keyboard::K))
		player2.shape.move(0.f, 8.f);
	if (Keyboard::isKeyPressed(Keyboard::J))
		player2.shape.move(-8.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::L))
		player2.shape.move(8.f, 0.f);

	//Sprawdzenie czy Gracz 2 wychodzi poza ekran, jeœli tak to ustawia go przy krawêdzi
	if (player2.shape.getPosition().x <= 0)
		player2.shape.setPosition(0.f, player2.shape.getPosition().y);
	if (player2.shape.getPosition().x >= window.getSize().x - player2.shape.getGlobalBounds().width)
		player2.shape.setPosition(window.getSize().x - player2.shape.getGlobalBounds().width, player2.shape.getPosition().y);
	if (player2.shape.getPosition().y <= 0)
		player2.shape.setPosition(player2.shape.getPosition().x, 0.f);
	if (player2.shape.getPosition().y >= window.getSize().y - player2.shape.getGlobalBounds().height)
		player2.shape.setPosition(player2.shape.getPosition().x, window.getSize().y - player2.shape.getGlobalBounds().height);
}

//Strzelanie Gracz 1
void shooting(Player& player, int& shootCooldown, vector<Enemy>& enemies, int& score, Resources& resources, RenderWindow& window) {

	if (shootCooldown < 20)
		shootCooldown++;

	if (Keyboard::isKeyPressed(Keyboard::Space) && shootCooldown >= 20) {
		resources.shoot.play();
		player.bullets.push_back(Bullet(&resources.bulletTxt, player.shape.getPosition()));
		shootCooldown = 0;
	}

	for (size_t i = 0; i < player.bullets.size(); i++)
	{
		player.bullets[i].shape.move(8.f, 0.f);

		//Usuwanie pocisków Gracza 1 jeœli s¹ poza ekranem
		if (player.bullets[i].shape.getPosition().x > window.getSize().x) {
			player.bullets.erase(player.bullets.begin() + i);
			break;
		}


		for (size_t k = 0; k < enemies.size(); k++)
		{
			//Sprawdzenie czy pocisk Gracza 1 trafia w przeciwnika
			if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds())) {
				if (enemies[k].HP <= 1) {
					score += 5;
					enemies.erase(enemies.begin() + k);
				}
				else
					enemies[k].HP--;
				player.bullets.erase(player.bullets.begin() + i);
				break;
			}
		}
	}
}

//Strzelanie Gracz 2
void shooting2(Player2& player2, int& shoot2Cooldown, vector<Enemy>& enemies, int& score2, Resources& resources, RenderWindow& window) {

	if (shoot2Cooldown < 20)
		shoot2Cooldown++;

	if (Keyboard::isKeyPressed(Keyboard::Return) && shoot2Cooldown >= 20) {
		player2.bullets2.push_back(Bullet2(&resources.bullet2Txt, player2.shape.getPosition()));
		shoot2Cooldown = 0;
	}

	for (size_t i = 0; i < player2.bullets2.size(); i++)
	{
		player2.bullets2[i].shape.move(8.f, 0.f);

		//Usuwanie pocisków Gracza 2 jeœli s¹ poza ekranem
		if (player2.bullets2[i].shape.getPosition().x > window.getSize().x) {
			player2.bullets2.erase(player2.bullets2.begin() + i);
			break;
		}
		for (size_t k = 0; k < enemies.size(); k++)
		{
			//Sprawdzenie czy pocisk Gracza 2 trafia w przeciwnika
			if (player2.bullets2[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds())) {
				if (enemies[k].HP <= 1) {
					score2 += 5;
					enemies.erase(enemies.begin() + k);
				}
				else
					enemies[k].HP--;
				player2.bullets2.erase(player2.bullets2.begin() + i);
				break;
			}
		}
	}
}

//Pojawianie siê przeciwników
void enemySpawn(vector<Enemy>& enemies, Resources& resources, int& enemySpawnCooldown, RenderWindow& window) {

	if (enemySpawnCooldown < 25)
		enemySpawnCooldown++;

	if (enemySpawnCooldown >= 25) {
		//Pojawianie siê przeciwników po prawej stronie okna
		enemies.push_back(Enemy(&resources.enemyTxt, window.getSize()));
		enemySpawnCooldown = 0;
	}
}

//Poruszanie siê przeciwników i sprawdzenie kolizji z graczem (Tryb SOLO)
void enemyCollisionSolo(Player& player, vector<Enemy>& enemies, Resources& resources, int& score) {
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].shape.move(-5.f, 0.f);
		if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width) {
			enemies.erase(enemies.begin() + i);
			break;
		}
		if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
			enemies.erase(enemies.begin() + i);
			player.HP--;
			resources.oof.play();
			break;
		}
	}
}

//Poruszanie siê przeciwników i sprawdzenie kolizji z graczem (Tryb DUO)
void enemyCollision(Player& player, Player2& player2, vector<Enemy>& enemies, Resources& resources, int& score, int& score2) {

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].shape.move(-5.f, 0.f);
		if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width) {
			enemies.erase(enemies.begin() + i);
			break;
		}
		if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
			enemies.erase(enemies.begin() + i);
			player.HP--;
			break;
		}
		if (enemies[i].shape.getGlobalBounds().intersects(player2.shape.getGlobalBounds())) {
			enemies.erase(enemies.begin() + i);
			player2.HP2--;
			break;
		}
	}
}

//Tryb gry: SOLO
void runGame(RenderWindow& gameWindow, Resources resources) {

	srand(time(NULL));
	gameWindow.setFramerateLimit(60);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	background.setTexture(&resources.soloTxt);

	RectangleShape pauseBgc;
	pauseBgc.setSize(Vector2f(960, 720));
	pauseBgc.setTexture(&resources.pauseTxt);

	Player player(&resources.playerTxt);
	player.shape.setPosition(10.f, gameWindow.getSize().y / 2.f - player.shape.getGlobalBounds().height / 2.f);

	Music music;
	music.openFromFile("MP3/unity.ogg");

	int score = 0;
	int shootCooldown = 20;
	int enemySpawnCooldown = 0;
	vector<Enemy> enemies;

	bool isPaused = false;
	bool isClosed = false;

	resources.shoot.setVolume(10);
	music.setVolume(1);
	music.play();

	while (gameWindow.isOpen())
	{
		Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				gameWindow.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					isClosed = !isClosed;
				}
				else if (event.key.code == Keyboard::F1) {
					isPaused = !isPaused;
				}
			}
		}
		if (!isClosed) {
			if (!isPaused) {
				if (player.HP > 0) {
					gameWindow.setTitle("SOLO Space Invaders");
					playerMovement(player, gameWindow);
					shooting(player, shootCooldown, enemies, score, resources, gameWindow);
					enemySpawn(enemies, resources, enemySpawnCooldown, gameWindow);
					enemyCollisionSolo(player, enemies, resources, score);

					resources.hpText.setString("HP: " + to_string(player.HP));
					resources.scoreText.setString("Score: " + to_string(score));
					resources.gameScoreText.setString("Twoj wynik: " + to_string(score));
				}
				gameWindow.clear();
				gameWindow.draw(background);
				gameWindow.draw(player.shape);
				gameWindow.draw(resources.scoreText);
				gameWindow.draw(resources.hpText);

				//Rysowanie pocisków
				for (size_t i = 0; i < player.bullets.size(); i++) {
					gameWindow.draw(player.bullets[i].shape);
				}

				//Rysowanie przeciwników
				for (size_t i = 0; i < enemies.size(); i++)
				{
					gameWindow.draw(enemies[i].shape);
				}

				//Gracz 1 odpadl - Koniec gry
				if (player.HP <= 0) {
					music.pause();
					resources.hpText.setString("");
					resources.scoreText.setString("");
					gameWindow.draw(resources.gameOverText);
					gameWindow.draw(resources.gameScoreText);
				}
			}
			//Okno pauzy F1
			else {
				gameWindow.clear();
				resources.pauseHpText.setString("Twoje aktualne HP: " + to_string(player.HP));
				gameWindow.setTitle("HELP");
				gameWindow.draw(pauseBgc);
				gameWindow.draw(resources.pauseHpText);
				gameWindow.draw(resources.gameScoreText);
				gameWindow.draw(resources.pauseText);
			}
		}
		//Okno zamkniecia ESC
		else {
			gameWindow.clear();
			gameWindow.setTitle("ESC");
			gameWindow.draw(pauseBgc);
			gameWindow.draw(resources.closeText);
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::F2)
					gameWindow.close();
			}
		}
		gameWindow.display();
	}
}

//Tryb gry DUO
void runDuo(RenderWindow& duoWindow, Resources& resources) {

	srand(time(NULL));
	duoWindow.setFramerateLimit(60);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	background.setTexture(&resources.duoTxt);

	Player player(&resources.playerTxt);
	player.shape.setPosition(10.f, duoWindow.getSize().y / 4.f - player.shape.getGlobalBounds().height / 2.f);

	Player2 player2(&resources.player2Txt);
	player2.shape.setPosition(10.f, ((duoWindow.getSize().y / 4.f) * 3.f) - player2.shape.getGlobalBounds().height / 2.f);

	Music music2;
	music2.openFromFile("MP3/better.ogg");

	int score = 0;
	int score2 = 0;
	int shootCooldown = 20;
	int shoot2Cooldown = 20;
	int enemySpawnCooldown = 0;

	vector<Enemy> enemies;

	resources.shoot.setVolume(0);
	music2.setVolume(10);
	music2.play();

	while (duoWindow.isOpen())
	{
		Event event;
		while (duoWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				duoWindow.close();
		}

		if (player.HP > 0 || player2.HP2 > 0) {

			playerMovement(player, duoWindow);
			player2Movement(player2, duoWindow);
			shooting(player, shootCooldown, enemies, score, resources, duoWindow);
			shooting2(player2, shoot2Cooldown, enemies, score2, resources, duoWindow);
			enemySpawn(enemies, resources, enemySpawnCooldown, duoWindow);
			enemyCollision(player, player2, enemies, resources, score, score2);

			if (player.HP > 0)
				resources.hpText.setString("G1 HP: " + to_string(player.HP));
			else {
				resources.hpText.setString("Gracz 1 odpadl!");
				player.shape.setPosition(-1000.f, 100.f);
				shootCooldown = 0;
			}
			resources.scoreText.setString("G1 Score: " + to_string(score));

			if (player2.HP2 > 0)
				resources.hp2Text.setString("G2 HP: " + to_string(player2.HP2));
			else {
				resources.hp2Text.setString("Gracz 2 odpadl!");
				player2.shape.setPosition(-1000.f, 100.f);
				shoot2Cooldown = 0;
			}
			resources.score2Text.setString("G2 Score: " + to_string(score2));
		}

		duoWindow.clear();
		duoWindow.draw(background);
		duoWindow.draw(player.shape);
		duoWindow.draw(player2.shape);
		duoWindow.draw(resources.scoreText);
		duoWindow.draw(resources.hpText);
		duoWindow.draw(resources.score2Text);
		duoWindow.draw(resources.hp2Text);
		//Rysowanie pocisków Gracza 1
		for (size_t i = 0; i < player.bullets.size(); i++) {
			duoWindow.draw(player.bullets[i].shape);
		}

		//Rysowanie pocisków Gracza 2
		for (size_t i = 0; i < player2.bullets2.size(); i++) {
			duoWindow.draw(player2.bullets2[i].shape);
		}

		//Rysowanie przeciwników
		for (size_t i = 0; i < enemies.size(); i++)
		{
			duoWindow.draw(enemies[i].shape);
		}

		//Koniec gry Gracz 1 i Gracz 2 odpadli
		if (player.HP <= 0 && player2.HP2 <= 0) {
			music2.pause();
			duoWindow.draw(resources.gameOverText);
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies.erase(enemies.begin() + i);
			}
			if (score > score2)
				duoWindow.draw(resources.playerWinsText);
			else if (score < score2)
				duoWindow.draw(resources.player2WinsText);
			else
				duoWindow.draw(resources.resultDrawText);
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			duoWindow.close();
			return;
		}
		duoWindow.display();
	}
}
//end 3

int main() {
	Resources resources;

	RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	background.setTexture(&resources.menuTxt);

	ConvexShape rysunek;
	rysunek.setPointCount(4);
	rysunek.setPoint(0, Vector2f(40, 70));
	rysunek.setPoint(1, Vector2f(60, 70));
	rysunek.setPoint(2, Vector2f(80, 140));
	rysunek.setPoint(3, Vector2f(100, 140));

	while (MENU.isOpen()) {
		Event event;
		while (MENU.pollEvent(event)) {
			if (event.type == Event::Closed) {
				MENU.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up) {
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down) {
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return) {
					RenderWindow Solo(VideoMode(960, 720), "SOLO Space Invaders");
					RenderWindow Duo(VideoMode(960, 720), "DUO Space Invaders");
					RenderWindow About(VideoMode(960, 720), "O grze");

					int x = mainMenu.MainMenuPressed();
					if (x == 0) {
						while (Solo.isOpen()) {
							Event aevent;
							while (Solo.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									Solo.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Solo.close();
									}
								}
							}
							Duo.close();
							About.close();
							runGame(Solo, resources);
						}
					}
					if (x == 1) {
						while (Duo.isOpen()) {
							Event aevent;
							while (Duo.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									Duo.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Duo.close();
									}
								}
							}
							Solo.close();
							About.close();
							runDuo(Duo, resources);

						}
					}
					if (x == 2) {
						AboutMe aboutMe(About.getSize().x, About.getSize().y);
						while (About.isOpen()) {
							Event aevent;
							while (About.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									About.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										About.close();
									}
								}
							}
							Solo.close();
							Duo.close();
							aboutMe.draw(About);
							About.display();
						}
					}
					if (x == 3)
						MENU.close();
					break;
				}
			}
		}
		MENU.clear();
		MENU.draw(background);
		MENU.draw(rysunek);
		mainMenu.draw(MENU);
		MENU.display();
	}
}