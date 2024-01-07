#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Menu.h"
#include "AboutMe.h"

void DuoSettings(RenderWindow& duoWindow) {

	Font font;
	font.loadFromFile("Fonts/Emulogic-zrEw.ttf");

	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(500.f, 10.f);
}