#include "App.h"

App::App() {
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	windowPtr = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Fullscreen, context_settings);
	windowPtr->setFramerateLimit(60);
	windowPtr->setVerticalSyncEnabled(true);
	windowPtr->setMouseCursorVisible(false);
}

void App::run() {

	std::unique_ptr<AppScreen> appScreen = std::make_unique<Game>(Game());

	while (windowPtr->isOpen()) {
		sf::Event event;
		while (windowPtr->pollEvent(event));
		{
			if (event.type == sf::Event::Closed) windowPtr->close();
		}

		if (checkIfWindowInFocus()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) windowPtr->close();
			appScreen->handleControls();
		}
		
		appScreen->update();

		windowPtr->clear();
		appScreen->draw(*windowPtr);
		windowPtr->display();
	}
}

bool App::checkIfWindowInFocus() const {
	return windowPtr->getSystemHandle() == GetFocus();
}
