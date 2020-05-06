#include <SFML/Graphics.hpp>
#include "Ship.h"

int main() {
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Fullscreen, context_settings);
	window.setFramerateLimit(60);
	bool window_focus = true;

	Ship ship;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event));
		{
			if (event.type == sf::Event::Closed) window.close();

			if(event.type == sf::Event::GainedFocus) window_focus = true;

			if(event.type == sf::Event::LostFocus) window_focus = false;
		}
		if (window_focus) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ship.turnLeft();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ship.turnRight();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ship.accelerate();
		}
		ship.updatePosition();

		window.clear();
		ship.draw(window);
		window.display();
	}
	return 0;
}