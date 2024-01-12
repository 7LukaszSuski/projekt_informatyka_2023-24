#include "resources.h"

Resources::Resources() {
	//Czcionka
	font.loadFromFile("Fonts/Emulogic-zrEw.ttf");
	//Tekstury
	duoTxt.loadFromFile("Texture/bgcDuo.jpg");
	playerTxt.loadFromFile("Texture/ship2.png");
	player2Txt.loadFromFile("Texture/player2.png");
	enemyTxt.loadFromFile("Texture/enemy.png");
	bulletTxt.loadFromFile("Texture/bullet2.png");
	bullet2Txt.loadFromFile("Texture/bullet2.png");
	soloTxt.loadFromFile("Texture/soloBgc.png");
	pauseTxt.loadFromFile("Texture/pauseBgc.png");
	menuTxt.loadFromFile("Texture/menuBgc.jpg");
	//Wynik Gracz 1
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(500.f, 10.f);
	//Wynik Gracz 2
	score2Text.setFont(font);
	score2Text.setCharacterSize(20);
	score2Text.setFillColor(Color::White);
	score2Text.setPosition(500.f, 50.f);
	//Koniec gry
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(960.f / 4, (720.f / 2) - 100.f);
	gameOverText.setString("GRA SKONCZONA!");
	//Tryb DUO - Gracz 1 wygra³
	playerWinsText.setFont(font);
	playerWinsText.setCharacterSize(30);
	playerWinsText.setFillColor(Color::Yellow);
	playerWinsText.setPosition(960.f / 4, (720.f / 2) - 50.f);
	playerWinsText.setString("GRACZ 1 WYGRAL!");
	//Tryb DUO - Gracz 2 wygra³
	player2WinsText.setFont(font);
	player2WinsText.setCharacterSize(30);
	player2WinsText.setFillColor(Color::Yellow);
	player2WinsText.setPosition(960.f / 4, (720.f / 2) - 50.f);
	player2WinsText.setString("GRACZ 2 WYGRAL!");
	//Tryb DUO - remis
	resultDrawText.setFont(font);
	resultDrawText.setCharacterSize(30);
	resultDrawText.setFillColor(Color::Yellow);
	resultDrawText.setPosition(960.f / 4, (720.f / 2) - 50.f);
	resultDrawText.setString("REMIS!");
	//Zdrowie - Gracz 1
	hpText.setFont(font);
	hpText.setCharacterSize(20);
	hpText.setFillColor(Color::White);
	hpText.setPosition(10.f, 10.f);
	//Zdrowie Gracz 2
	hp2Text.setFont(font);
	hp2Text.setCharacterSize(20);
	hp2Text.setFillColor(Color::White);
	hp2Text.setPosition(10.f, 50.f);
	//Tryb SOLO - wynik koñcowy
	gameScoreText.setFont(font);
	gameScoreText.setCharacterSize(30);
	gameScoreText.setFillColor(Color::Yellow);
	gameScoreText.setPosition((960.f / 4), (720.f / 2) - 50.f);
	//Tryb pauzy - zdrowie Gracza
	pauseHpText.setFont(font);
	pauseHpText.setCharacterSize(30);
	pauseHpText.setFillColor(Color::White);
	pauseHpText.setPosition(100.f, (720.f / 2) + 100);
	//Tryb pauzy - informacje
	pauseText.setFont(font);
	pauseText.setCharacterSize(30);
	pauseText.setFillColor(Color::White);
	pauseText.setPosition(100.f, 150.f);
	pauseText.setString("GRA ZATRZYMANA. \nNacisnij F1, aby wznowic.");
	//Tryb ESC - informacje
	closeText.setFont(font);
	closeText.setCharacterSize(30);
	closeText.setFillColor(Color::White);
	closeText.setPosition(100.f, 150.f);
	closeText.setString("Czy na pewno chcesz wyjsc? \nNacisnij F2 jesli TAK. \nNacisnij ESC jesli NIE.");
	//DŸwiêk strza³u
	pew.loadFromFile("MP3/shoot.ogg");
	shoot.setBuffer(pew);
	//DŸwiêk utraty zdrowia
	of.loadFromFile("MP3/oof.ogg");
	oof.setBuffer(of);
}