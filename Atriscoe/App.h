#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Ship.h"
#include "Animation.h"
#include "ShipExhaust.h"
#include "ShipExplosion.h"
#include "Asteroid.h"
#include "AsteroidExplosion.h"

class App {
public:
	App();
	void run();
private:
	bool checkIfWindowInFocus() const;
	std::unique_ptr<sf::RenderWindow> windowPtr;
	const int bulletReloadPeriod{ 60 };
	int bulletReloadTimeLeft{ 30 };
};
