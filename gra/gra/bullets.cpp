#include "bullets.h"
using namespace sf;
//Klasa Bullet (wska�nik do tekstury i pozycja)
Bullet::Bullet(Texture* texture, Vector2f pos) {
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(pos);
}
//Klasa Bullet2 (wska�nik do tekstury i pozycja)
Bullet2::Bullet2(Texture* texture, Vector2f pos) {
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(pos);
}
