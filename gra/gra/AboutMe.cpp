#include "AboutMe.h"
using namespace sf;

AboutMe::AboutMe(float width, float height) {
    font.loadFromFile("Fonts/zai_ConsulPolishTypewriter.ttf"); 

    aboutText.setFont(font);
    aboutText.setCharacterSize(20);
    aboutText.setFillColor(Color::White);
    aboutText.setString("Gra typu Space Shooter posiadaj¹ca dwa tryby.\n Pierwszy tryb jest to rozgrywka solo.\n Drugi tryb jest to rozgrywka duo z partnerem.");

    aboutText.setPosition(width / 4, height / 4);
}

void AboutMe::draw(RenderWindow& window) {
    window.draw(aboutText);
}
