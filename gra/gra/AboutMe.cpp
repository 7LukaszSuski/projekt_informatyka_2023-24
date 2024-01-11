#include "AboutMe.h"
using namespace sf;

AboutMe::AboutMe(float width, float height) {
    font.loadFromFile("Fonts/zai_ConsulPolishTypewriter.ttf"); 

    aboutText.setFont(font);
    aboutText.setCharacterSize(30);
    aboutText.setFillColor(Color::White);
    aboutText.setString("Gra typu Space Shooter posiadajaca dwa tryby.\nPierwszy tryb jest to rozgrywka solo.\nDrugi tryb jest to rozgrywka duo z partnerem. \n\nSterowanie Graczem 1: \nW - w gore \nS - w dol \nA - w lewo \nD - w prawo \nSPACJA - strzal \n\nSterowanie Graczem 2: \nI - w gore \nK - w dol \nJ - w lewo \nL - w prawo \nENTER - strzal");
    aboutText.setPosition(width / 8, height / 16);
}

void AboutMe::draw(RenderWindow& window) {
    window.draw(aboutText);
}
