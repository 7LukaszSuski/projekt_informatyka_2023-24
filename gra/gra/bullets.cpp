#include "bullets.h"
using namespace sf;

Bullet::Bullet(Texture* texture, Vector2f pos) {
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(pos);
}

Bullet2::Bullet2(Texture* texture, Vector2f pos) {
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(pos);
}
