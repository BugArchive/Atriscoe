#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "AppScreen.h"
#include "Game.h"

class App {
public:
	App();
	void run();
private:
	bool checkIfWindowInFocus() const;
	std::unique_ptr<sf::RenderWindow> windowPtr;
};
