#include "Menu.h"

MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/Emulogic-zrEw.ttf")) {
		cout << "Brak czcionki!";
	}
	//Tryb SOLO
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("SOLO");
	mainMenu[0].setCharacterSize(80);
	mainMenu[0].setPosition(50, 150);
	//Tryb DUO
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("DUO");
	mainMenu[1].setCharacterSize(80);
	mainMenu[1].setPosition(50, 300);
	//O grze
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("O grze");
	mainMenu[2].setCharacterSize(80);
	mainMenu[2].setPosition(50, 450);
	//Wyjœcie
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(80);
	mainMenu[3].setPosition(50, 600);

	MainMenuSelected = -1;
}
//Rysowanie MENU
void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; ++i) {
		window.draw(mainMenu[i]);
	}
}
//Zmiana pola - strza³ka w góre
void MainMenu::MoveUp() {
	if (MainMenuSelected + 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 3;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Cyan);
	}
}
//Zmiana pola - strza³ka w dó³
void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Cyan);
	}
}