#include "App.h"

App::App() {
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	windowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Fullscreen, context_settings);
	windowPtr->setFramerateLimit(60);
	windowPtr->setVerticalSyncEnabled(true);
	windowPtr->setMouseCursorVisible(false);
	isWindowInFocus = true;
}

void App::run() {

	Ship ship;

	while (windowPtr->isOpen()) {
		sf::Event event;
		while (windowPtr->pollEvent(event));
		{
			if (event.type == sf::Event::Closed) windowPtr->close();

			if(event.type == sf::Event::GainedFocus) isWindowInFocus = true;

			if(event.type == sf::Event::LostFocus) isWindowInFocus = false;
		}
		if (isWindowInFocus) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) windowPtr->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ship.turnLeft();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ship.turnRight();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ship.accelerate();
		}
		ship.updatePosition();

		windowPtr->clear();
		ship.draw(*windowPtr);
		windowPtr->display();
	}
}