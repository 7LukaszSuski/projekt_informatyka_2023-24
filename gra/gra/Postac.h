/*#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Postac
{
public:
	Postac(float x, float y) {
		circle.setSize(sf::Vector2f(x, y));
	}
	void drawTo(sf::RenderWindow& window) {
		window.draw(circle);
	}
private:
	sf::CircleShape circle;
};

