#include "Menu.h"

MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/Emulogic-zrEw.ttf")) {
		cout << "Brak czcionki!";
	}

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("SOLO");
	mainMenu[0].setCharacterSize(80);
	mainMenu[0].setPosition(50, 150);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("DUO");
	mainMenu[1].setCharacterSize(80);
	mainMenu[1].setPosition(50, 300);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("O grze");
	mainMenu[2].setCharacterSize(80);
	mainMenu[2].setPosition(50, 450);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(80);
	mainMenu[3].setPosition(50, 600);

	MainMenuSelected = -1;
}

void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; ++i) {
		window.draw(mainMenu[i]);
	}
}
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