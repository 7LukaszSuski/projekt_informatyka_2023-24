#include "resources.h"

Resources::Resources() {

	font.loadFromFile("Fonts/Emulogic-zrEw.ttf");

	duoTxt.loadFromFile("Texture/bgcDuo.jpg");
	playerTxt.loadFromFile("Texture/ship2.png");
	player2Txt.loadFromFile("Texture/player2.png");
	enemyTxt.loadFromFile("Texture/enemy.png");
	bulletTxt.loadFromFile("Texture/bullet2.png");
	bullet2Txt.loadFromFile("Texture/bullet2.png");
	soloTxt.loadFromFile("Texture/soloBgc.png");
	pauseTxt.loadFromFile("Texture/pauseBgc.png");
	menuTxt.loadFromFile("Texture/menuBgc.jpg");

	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(500.f, 10.f);

	score2Text.setFont(font);
	score2Text.setCharacterSize(20);
	score2Text.setFillColor(Color::White);
	score2Text.setPosition(500.f, 50.f);

	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(960.f / 4, (720.f / 2) - 100.f);
	gameOverText.setString("GRA SKONCZONA!");

	playerWinsText.setFont(font);
	playerWinsText.setCharacterSize(30);
	playerWinsText.setFillColor(Color::Yellow);
	playerWinsText.setPosition(960.f / 4, (720.f / 2) - 50.f);
	playerWinsText.setString("GRACZ 1 WYGRAL!");

	player2WinsText.setFont(font);
	player2WinsText.setCharacterSize(30);
	player2WinsText.setFillColor(Color::Yellow);
	player2WinsText.setPosition(960.f / 4, (720.f / 2) - 50.f);
	player2WinsText.setString("GRACZ 2 WYGRAL!");

	resultDrawText.setFont(font);
	resultDrawText.setCharacterSize(30);
	resultDrawText.setFillColor(Color::Yellow);
	resultDrawText.setPosition(960.f / 4, (720.f / 2) - 50.f);
	resultDrawText.setString("REMIS!");

	hpText.setFont(font);
	hpText.setCharacterSize(20);
	hpText.setFillColor(Color::White);
	hpText.setPosition(10.f, 10.f);

	hp2Text.setFont(font);
	hp2Text.setCharacterSize(20);
	hp2Text.setFillColor(Color::White);
	hp2Text.setPosition(10.f, 50.f);

	gameScoreText.setFont(font);
	gameScoreText.setCharacterSize(30);
	gameScoreText.setFillColor(Color::Yellow);
	gameScoreText.setPosition((960.f / 4), (720.f / 2) - 50.f);

	pauseHpText.setFont(font);
	pauseHpText.setCharacterSize(30);
	pauseHpText.setFillColor(Color::White);
	pauseHpText.setPosition(100.f, (720.f / 2) + 100);

	pauseText.setFont(font);
	pauseText.setCharacterSize(30);
	pauseText.setFillColor(Color::White);
	pauseText.setPosition(100.f, 150.f);
	pauseText.setString("GRA ZATRZYMANA. \nNacisnij F1, aby wznowic.");

	closeText.setFont(font);
	closeText.setCharacterSize(30);
	closeText.setFillColor(Color::White);
	closeText.setPosition(100.f, 150.f);
	closeText.setString("Czy na pewno chcesz wyjsc? \nNacisnij F2 jesli TAK. \nNacisnij ESC jesli NIE.");

	pew.loadFromFile("MP3/shoot.ogg");
	shoot.setBuffer(pew);

	of.loadFromFile("MP3/oof.ogg");
	oof.setBuffer(of);
}