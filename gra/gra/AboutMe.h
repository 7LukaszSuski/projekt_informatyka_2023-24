#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class AboutMe {
public:
    AboutMe(float width, float height);

    void draw(RenderWindow& window);

private:
    Font font;
    Text aboutText;
};