#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Menu.h"
#include "AboutMe.h"
#include "Text.cpp"
using namespace std;
using namespace sf;

//add 2
class Bullet {
public:
	Sprite shape;
	Bullet(Texture* texture, Vector2f pos) {
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
		this->shape.setPosition(pos);
	}
	~Bullet() {}
};
class Player
{
public:
	Sprite shape;
	Texture* texture;
	int HP;
	int HPMax;
	vector<Bullet> bullets;

	Player(Texture* texture) {
		this->HPMax = 5;
		this->HP = this->HPMax;

		this->texture = texture;
		this->shape.setTexture(*texture);

		this->shape.setScale(0.1f, 0.1f);


	}
	~Player() {}
};
class Enemy {
public:
	Sprite shape;
	int HP;
	Enemy(Texture* texture, Vector2u windowSize) {
		this->HP = 1;
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
		this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
	}
	~Enemy() {}
};
//end 2

//add 10
class Bullet2 {
public:
	Sprite shape;
	Bullet2(Texture* texture, Vector2f pos) {
		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
		this->shape.setPosition(pos);
	}
	~Bullet2() {}
};

class Player2
{
public:
	Sprite shape;
	Texture* texture;
	int HP2;
	int HP2Max;
	vector<Bullet2> bullets2;

	Player2(Texture* texture) {
		this->HP2Max = 5;
		this->HP2 = this->HP2Max;

		this->texture = texture;
		this->shape.setTexture(*texture);

		this->shape.setScale(0.1f, 0.1f);


	}
	~Player2() {}
};
//end 10

//add 11

void runDuo(RenderWindow& duoWindow) {

	srand(time(NULL));
	duoWindow.setFramerateLimit(60);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Texture/bgcDuo.jpg");
	background.setTexture(&Maintexture);

	Font font;
	font.loadFromFile("Fonts/Emulogic-zrEw.ttf");

	Texture playerTex;
	playerTex.loadFromFile("Texture/ship2.png");

	Texture player2Tex;
	player2Tex.loadFromFile("Texture/player2.png");

	Texture enemyTex;
	enemyTex.loadFromFile("Texture/enemy.png");

	Texture bulletTex;
	bulletTex.loadFromFile("Texture/bullet2.png");

	Texture bullet2Tex;
	bullet2Tex.loadFromFile("Texture/bullet2.png");

	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(500.f, 10.f);

	Text score2Text;
	score2Text.setFont(font);
	score2Text.setCharacterSize(20);
	score2Text.setFillColor(Color::White);
	score2Text.setPosition(500.f, 50.f);

	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(100.f, duoWindow.getSize().y / 2);
	gameOverText.setString("GRA SKONCZONA!");

	Text playerWins;
	playerWins.setFont(font);
	playerWins.setCharacterSize(30);
	playerWins.setFillColor(Color::Yellow);
	playerWins.setPosition(100.f, (duoWindow.getSize().y / 2) + 100.f);
	playerWins.setString("GRACZ 1 WYGRAL!");

	Text player2Wins;
	player2Wins.setFont(font);
	player2Wins.setCharacterSize(30);
	player2Wins.setFillColor(Color::Yellow);
	player2Wins.setPosition(100.f, (duoWindow.getSize().y / 2) + 100.f);
	player2Wins.setString("GRACZ 2 WYGRAL!");

	Text resultDraw;
	resultDraw.setFont(font);
	resultDraw.setCharacterSize(30);
	resultDraw.setFillColor(Color::Yellow);
	resultDraw.setPosition(100.f, (duoWindow.getSize().y / 2) + 100.f);
	resultDraw.setString("REMIS!");

	int score = 0;
	Player player(&playerTex);
	player.shape.setPosition(10.f, duoWindow.getSize().y / 4.f - player.shape.getGlobalBounds().height / 2.f);
	int shootTimer = 20;
	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(20);
	hpText.setFillColor(Color::White);
	hpText.setPosition(10.f, 10.f);

	int score2 = 0;
	Player2 player2(&player2Tex);
	player2.shape.setPosition(10.f, ((duoWindow.getSize().y / 4.f) * 3.f) - player2.shape.getGlobalBounds().height / 2.f);
	int shoot2Timer = 20;
	Text hp2Text;
	hp2Text.setFont(font);
	hp2Text.setCharacterSize(20);
	hp2Text.setFillColor(Color::White);
	hp2Text.setPosition(10.f, 50.f);

	int enemySpawnTimer = 0;
	vector<Enemy> enemies;

	while (duoWindow.isOpen())
	{
		Event event;
		while (duoWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				duoWindow.close();
		}

		if (player.HP > 0 || player2.HP2 > 0) {

			if (Keyboard::isKeyPressed(Keyboard::W))
				player.shape.move(0.f, -8.f);
			if (Keyboard::isKeyPressed(Keyboard::S))
				player.shape.move(0.f, 8.f);
			if (Keyboard::isKeyPressed(Keyboard::A))
				player.shape.move(-8.f, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::D))
				player.shape.move(8.f, 0.f);

			if (Keyboard::isKeyPressed(Keyboard::I))
				player2.shape.move(0.f, -8.f);
			if (Keyboard::isKeyPressed(Keyboard::K))
				player2.shape.move(0.f, 8.f);
			if (Keyboard::isKeyPressed(Keyboard::J))
				player2.shape.move(-8.f, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::L))
				player2.shape.move(8.f, 0.f);

			if (player.shape.getPosition().x <= 0)
				player.shape.setPosition(0.f, player.shape.getPosition().y);
			if (player.shape.getPosition().x >= duoWindow.getSize().x - player.shape.getGlobalBounds().width)
				player.shape.setPosition(duoWindow.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
			if (player.shape.getPosition().y <= 0)
				player.shape.setPosition(player.shape.getPosition().x, 0.f);
			if (player.shape.getPosition().y >= duoWindow.getSize().y - player.shape.getGlobalBounds().height)
				player.shape.setPosition(player.shape.getPosition().x, duoWindow.getSize().y - player.shape.getGlobalBounds().height);

			if (player2.shape.getPosition().x <= 0)
				player2.shape.setPosition(0.f, player2.shape.getPosition().y);
			if (player2.shape.getPosition().x >= duoWindow.getSize().x - player2.shape.getGlobalBounds().width)
				player2.shape.setPosition(duoWindow.getSize().x - player2.shape.getGlobalBounds().width, player2.shape.getPosition().y);
			if (player2.shape.getPosition().y <= 0)
				player2.shape.setPosition(player2.shape.getPosition().x, 0.f);
			if (player2.shape.getPosition().y >= duoWindow.getSize().y - player2.shape.getGlobalBounds().height)
				player2.shape.setPosition(player2.shape.getPosition().x, duoWindow.getSize().y - player2.shape.getGlobalBounds().height);

			if (shootTimer < 20)
				shootTimer++;

			if (shoot2Timer < 20)
				shoot2Timer++;

			if (Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >= 20) {
				player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
				shootTimer = 0;
			}

			if (Keyboard::isKeyPressed(Keyboard::Return) && shoot2Timer >= 20) {
				player2.bullets2.push_back(Bullet2(&bullet2Tex, player2.shape.getPosition()));
				shoot2Timer = 0;
			}

			for (size_t i = 0; i < player.bullets.size(); i++)
			{
				player.bullets[i].shape.move(8.f, 0.f);

				if (player.bullets[i].shape.getPosition().x > duoWindow.getSize().x) {
					player.bullets.erase(player.bullets.begin() + i);
					break;
				}


				for (size_t k = 0; k < enemies.size(); k++)
				{
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
			for (size_t i = 0; i < player2.bullets2.size(); i++)
			{
				player2.bullets2[i].shape.move(8.f, 0.f);

				if (player2.bullets2[i].shape.getPosition().x > duoWindow.getSize().x) {
					player2.bullets2.erase(player2.bullets2.begin() + i);
					break;
				}
				for (size_t k = 0; k < enemies.size(); k++)
				{
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

			if (enemySpawnTimer < 25)
				enemySpawnTimer++;

			if (enemySpawnTimer >= 25) {
				enemies.push_back(Enemy(&enemyTex, duoWindow.getSize()));
				enemySpawnTimer = 0;
			}
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
			if (player.HP > 0)
				hpText.setString("G1 HP: " + to_string(player.HP));
			else {
				hpText.setString("Gracz 1 odpada!");
				player.shape.setPosition(-1000.f, 100.f);
				shootTimer = 0;
			}
			scoreText.setString("G1 Score: " + to_string(score));

			if (player2.HP2 > 0)
				hp2Text.setString("G2 HP: " + to_string(player2.HP2));
			else {
				hp2Text.setString("Gracz 2 odpada!");
				player2.shape.setPosition(-1000.f, 100.f);
				shoot2Timer = 0;
			}
			score2Text.setString("G2 Score: " + to_string(score2));
		}
		duoWindow.clear();
		duoWindow.draw(background);
		duoWindow.draw(player.shape);
		duoWindow.draw(player2.shape);
		for (size_t i = 0; i < player.bullets.size(); i++) {
			duoWindow.draw(player.bullets[i].shape);
		}
		for (size_t i = 0; i < player2.bullets2.size(); i++) {
			duoWindow.draw(player2.bullets2[i].shape);
		}

		for (size_t i = 0; i < enemies.size(); i++)
		{
			duoWindow.draw(enemies[i].shape);
		}

		duoWindow.draw(scoreText);
		duoWindow.draw(hpText);
		duoWindow.draw(score2Text);
		duoWindow.draw(hp2Text);



		if (player.HP <= 0 && player2.HP2 <= 0) {
			duoWindow.draw(gameOverText);
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies.erase(enemies.begin() + i);
			}
			if (score > score2)
				duoWindow.draw(playerWins);
			else if (score < score2)
				duoWindow.draw(player2Wins);
			else
				duoWindow.draw(resultDraw);
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			duoWindow.close();

		duoWindow.display();
	}

}

//end 11

//add 3
void runGame(RenderWindow& gameWindow) {
	
		srand(time(NULL));
		gameWindow.setFramerateLimit(60);

		RectangleShape background;
		background.setSize(Vector2f(960, 720));
		Texture Maintexture;
		Maintexture.loadFromFile("Texture/soloBgc.png");
		background.setTexture(&Maintexture);

		RectangleShape pauseBgc;
		pauseBgc.setSize(Vector2f(960, 720));
		Texture pauseTxt;
		pauseTxt.loadFromFile("Texture/pauseBgc.png");
		pauseBgc.setTexture(&pauseTxt);

		RectangleShape closeBgc;
		closeBgc.setSize(Vector2f(960, 720));
		Texture closeTxt;
		closeTxt.loadFromFile("Texture/pauseBgc.png");
		closeBgc.setTexture(&closeTxt);

		Font font;
		font.loadFromFile("Fonts/Emulogic-zrEw.ttf");

		Texture playerTex;
		playerTex.loadFromFile("Texture/ship2.png");

		Texture enemyTex;
		enemyTex.loadFromFile("Texture/enemy.png");

		Texture bulletTex;
		bulletTex.loadFromFile("Texture/bullet.png");

		Text scoreText;
		scoreText.setFont(font);
		scoreText.setCharacterSize(20);
		scoreText.setFillColor(Color::White);
		scoreText.setPosition(700.f, 10.f);

		Text gameScore;
		gameScore.setFont(font);
		gameScore.setCharacterSize(30);
		gameScore.setFillColor(Color::Yellow);
		gameScore.setPosition(100.f, (gameWindow.getSize().y / 2)+50);

		Text gameOverText;
		gameOverText.setFont(font);
		gameOverText.setCharacterSize(30);
		gameOverText.setFillColor(Color::Red);
		gameOverText.setPosition(100.f, gameWindow.getSize().y / 2);
		gameOverText.setString("GRA SKONCZONA!");

		int score = 0;
		Player player(&playerTex);
		player.shape.setPosition(10.f, gameWindow.getSize().y / 2.f - player.shape.getGlobalBounds().height / 2.f);
		int shootTimer = 40;
		Text hpText;
		hpText.setFont(font);
		hpText.setCharacterSize(20);
		hpText.setFillColor(Color::White);
		hpText.setPosition(10.f, 10.f);

		int enemySpawnTimer = 0;
		vector<Enemy> enemies;

		Text pauseHpText;
		pauseHpText.setFont(font);
		pauseHpText.setCharacterSize(30);
		pauseHpText.setFillColor(Color::White);
		pauseHpText.setPosition(100.f, (gameWindow.getSize().y / 2) + 100);

		//pauza 1
		bool isPaused = false;
		Text pauseText;
		pauseText.setFont(font);
		pauseText.setCharacterSize(30);
		pauseText.setFillColor(Color::White);
		pauseText.setPosition(100.f, 150.f);
		pauseText.setString("GRA ZATRZYMANA. \nNacisnij F1, aby wznowic.");
		// 1 pauza

		while (gameWindow.isOpen())
		{
			Event event;
			while (gameWindow.pollEvent(event))
			{
				if (event.type == Event::Closed)
					gameWindow.close();
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Escape) {
						gameWindow.close();
					}
					else if (event.key.code == Keyboard::F1) {
						isPaused = !isPaused;
					}
				}
			}
			if (!isPaused) {
				if (player.HP > 0) {

					if (Keyboard::isKeyPressed(Keyboard::W))
						player.shape.move(0.f, -8.f);
					if (Keyboard::isKeyPressed(Keyboard::S))
						player.shape.move(0.f, 8.f);
					if (Keyboard::isKeyPressed(Keyboard::A))
						player.shape.move(-8.f, 0.f);
					if (Keyboard::isKeyPressed(Keyboard::D))
						player.shape.move(8.f, 0.f);

					if (player.shape.getPosition().x <= 0)
						player.shape.setPosition(0.f, player.shape.getPosition().y);
					if (player.shape.getPosition().x >= gameWindow.getSize().x - player.shape.getGlobalBounds().width)
						player.shape.setPosition(gameWindow.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
					if (player.shape.getPosition().y <= 0)
						player.shape.setPosition(player.shape.getPosition().x, 0.f);
					if (player.shape.getPosition().y >= gameWindow.getSize().y - player.shape.getGlobalBounds().height)
						player.shape.setPosition(player.shape.getPosition().x, gameWindow.getSize().y - player.shape.getGlobalBounds().height);

					if (shootTimer < 40)
						shootTimer++;

					if (Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >= 20) {
						player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
						shootTimer = 0;
					}

					for (size_t i = 0; i < player.bullets.size(); i++)
					{
						player.bullets[i].shape.move(8.f, 0.f);

						if (player.bullets[i].shape.getPosition().x > gameWindow.getSize().x) {
							player.bullets.erase(player.bullets.begin() + i);
							break;
						}

						for (size_t k = 0; k < enemies.size(); k++)
						{
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

					if (enemySpawnTimer < 25)
						enemySpawnTimer++;

					if (enemySpawnTimer >= 25) {
						enemies.push_back(Enemy(&enemyTex, gameWindow.getSize()));
						enemySpawnTimer = 0;
					}
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
					}

					hpText.setString("HP: " + to_string(player.HP));
					scoreText.setString("Score: " + to_string(score));
					gameScore.setString("Twoj wynik: " + to_string(score));
				}
				gameWindow.clear();
				gameWindow.draw(background);
				gameWindow.draw(player.shape);
				for (size_t i = 0; i < player.bullets.size(); i++) {
					gameWindow.draw(player.bullets[i].shape);
				}

				for (size_t i = 0; i < enemies.size(); i++)
				{
					gameWindow.draw(enemies[i].shape);
				}

				gameWindow.draw(scoreText);
				gameWindow.draw(hpText);


				if (player.HP <= 0) {
					gameWindow.draw(gameOverText);
					gameWindow.draw(gameScore);
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape))
					gameWindow.close();
				
			}
			else {
				gameWindow.clear();
				gameWindow.setTitle("HELP");
				gameWindow.draw(pauseBgc);
				pauseHpText.setString("Twoje aktualne HP: " + to_string(player.HP));
				gameWindow.draw(pauseHpText);
				gameWindow.draw(gameScore);
				gameWindow.draw(pauseText);
			}

			gameWindow.display();
		}

	
}
//end 3

int main() {
	RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Texture/menuBgc.jpg");
	background.setTexture(&Maintexture);

	RectangleShape Obgc;
	Obgc.setSize(Vector2f(960, 720));
	Texture Otxt;
	Otxt.loadFromFile("Texture/opcje.jpg");
	Obgc.setTexture(&Otxt);

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
					RenderWindow About(VideoMode(960, 720), "O mnie");

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
							runGame(Solo);
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
							Duo.clear();
							About.close();
							runDuo(Duo);

							Duo.display();
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
							About.clear();
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
		mainMenu.draw(MENU);
		MENU.display();
	}
}