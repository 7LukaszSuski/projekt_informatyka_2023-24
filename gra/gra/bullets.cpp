#include "bullets.h"
using namespace sf;
//Klasa Bullet (wskaünik do tekstury i pozycja)
Bullet::Bullet(Texture* texture, Vector2f pos) {
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(pos);
}
//Klasa Bullet2 (wskaünik do tekstury i pozycja)
Bullet2::Bullet2(Texture* texture, Vector2f pos) {
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(pos);
}
