#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemy
{
public:
	Enemy(Texture* texture, Vector2u windowSize);

	Sprite shape;
	int HP;
};

