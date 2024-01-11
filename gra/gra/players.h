#pragma once
#include <SFML/Graphics.hpp>
#include "bullets.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Player(Texture* texture);

	Sprite shape;
	int HP;
	int HPMax;
	vector<Bullet> bullets;
};
class Player2
{
public:
	Player2(Texture* texture);

	Sprite shape;
	int HP2;
	int HP2Max;
	vector<Bullet2> bullets2;
};
