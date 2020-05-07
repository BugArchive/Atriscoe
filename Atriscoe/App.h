#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Ship.h"

class App {
public:
	App();
	void run();
private:
	std::unique_ptr<sf::RenderWindow> windowPtr;
	bool isWindowInFocus = true;
};

