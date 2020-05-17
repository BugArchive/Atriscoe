#pragma once
#include <SFML/Graphics.hpp>
class AppScreen {
public:
	virtual void handleControls() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) const = 0;
};
