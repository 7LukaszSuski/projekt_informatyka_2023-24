#pragma once

#include <SFML/Graphics.hpp>

class AboutMe {
public:
    AboutMe(float width, float height);

    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text aboutText;
};