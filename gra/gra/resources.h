#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Resources {
public:
	Resources();

	Font font;

	Texture duoTxt;
	Texture playerTxt;
	Texture player2Txt;
	Texture enemyTxt;
	Texture bulletTxt;
	Texture bullet2Txt;
	Texture soloTxt;
	Texture pauseTxt;
	Texture menuTxt;

	Text scoreText;
	Text score2Text;
	Text gameOverText;
	Text playerWinsText;
	Text player2WinsText;
	Text resultDrawText;
	Text hpText;
	Text hp2Text;
	Text gameScoreText;
	Text pauseHpText;
	Text pauseText;
	Text closeText;

	SoundBuffer pew;
	Sound shoot;

	SoundBuffer of;
	Sound oof;
};
