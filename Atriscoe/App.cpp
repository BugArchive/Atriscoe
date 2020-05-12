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

	Ship ship;
	Asteroid asteroid;
	std::vector<Bullet> bullets;

	while (windowPtr->isOpen()) {
		sf::Event event;
		while (windowPtr->pollEvent(event));
		{
			if (event.type == sf::Event::Closed) windowPtr->close();
		}
		if (checkIfWindowInFocus()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) windowPtr->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ship.turnLeft();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ship.turnRight();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ship.accelerate();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (bulletReloadTime == 0) {
					bullets.emplace_back(ship.spawnBullet());
					bulletReloadTime = bulletReloadPeriod;
				}
			};
		}
		for (auto b_it = bullets.begin(); b_it != bullets.end(); ++b_it) {
			if (b_it->checkIfCollidingWith(asteroid)) {
				bullets.erase(b_it);
				asteroid = Asteroid();
				break;
			}
		}
		if (ship.checkIfCollidingWith(asteroid)) {
			asteroid = Asteroid();
		}

		if (bulletReloadTime > 0) bulletReloadTime--;
		bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& bullet) { return !bullet.updateWithLifetime(); }), bullets.end());
		asteroid.update();
		ship.updatePosition();

		windowPtr->clear();
		for (const auto& bullet : bullets) {
			bullet.draw(*windowPtr);
		}
		asteroid.draw(*windowPtr);
		ship.draw(*windowPtr);
		windowPtr->display();
	}
}

bool App::checkIfWindowInFocus() const {
	return windowPtr->getSystemHandle() == GetFocus();
}
