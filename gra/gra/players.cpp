#include "players.h"
using namespace sf;

Player::Player(Texture* texture) {
	HPMax = 5;
	HP = HPMax;

	texture = texture;
	shape.setTexture(*texture);
	shape.setScale(0.1f, 0.1f);
}

Player2::Player2(Texture* texture) {
	HP2Max = 5;
	HP2 = HP2Max;

	texture = texture;
	shape.setTexture(*texture);
	shape.setScale(0.1f, 0.1f);
}