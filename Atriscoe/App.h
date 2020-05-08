#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Ship.h"
#include "Asteroid.h"

class App {
public:
	App();
	void run();
private:
	bool checkIfWindowInFocus() const;
	std::unique_ptr<sf::RenderWindow> windowPtr;
};

