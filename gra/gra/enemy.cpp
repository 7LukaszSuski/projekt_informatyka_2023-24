#include "enemy.h"
using namespace sf;

Enemy::Enemy(Texture* texture, Vector2u windowSize) {
	HP = 1;
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}