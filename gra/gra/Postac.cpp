/*#include <iostream>
#include "Postac.h"
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(960, 720), "title");
	sf::Event event;
	Postac player(window.getSize().x / 2, window.getSize().y / 2);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		player.drawTo(window);
		window.display();
	}

}
