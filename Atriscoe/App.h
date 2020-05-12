#pragma once
#include <memory>
#include <vector>
#include <algorithm>
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
	const int bulletReloadPeriod{ 60 };
	int bulletReloadTime{ 30 };
};
