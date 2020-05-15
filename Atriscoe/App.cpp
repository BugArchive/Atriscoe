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
	std::vector<Asteroid> asteroids;
	asteroids.emplace_back(Asteroid());
	asteroids.emplace_back(Asteroid());
	std::vector<Bullet> bullets;
	std::vector<std::unique_ptr<Animation>> animationsPtrs;

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				ship.accelerate();
				animationsPtrs.emplace_back(std::make_unique<ShipExhaust>(ship.spawnExhaust()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (bulletReloadTimeLeft == 0) {
					bullets.emplace_back(ship.spawnBullet());
					bulletReloadTimeLeft = bulletReloadPeriod;
				}
			};
		}
		for (auto b_it = bullets.begin(); b_it != bullets.end();) {
			bool is_bullet_erased = false;
			for (auto a_it = asteroids.begin(); a_it != asteroids.end(); ++a_it) {
				if (b_it->checkIfCollidingWith(*a_it)) {
					b_it = bullets.erase(b_it);
					is_bullet_erased = true;
					sf::Vector2f collided_asteroid_position = a_it->getPosition();
					int collided_asteroid_size = a_it->getSize();
					animationsPtrs.emplace_back(std::make_unique<AsteroidExplosion>(a_it->spawnExplosion()));
					asteroids.erase(a_it);
					if (collided_asteroid_size > 1) {
						asteroids.emplace_back(collided_asteroid_position, collided_asteroid_size - 1);
						asteroids.emplace_back(collided_asteroid_position, collided_asteroid_size - 1);
						asteroids.emplace_back(collided_asteroid_position, collided_asteroid_size - 1);
					}
					break;
				}
			}
			if (!is_bullet_erased) ++b_it;
		}
		for (const auto& asteroid : asteroids) {
			if (ship.checkIfCollidingWith(asteroid)) {
				animationsPtrs.emplace_back(std::make_unique<ShipExplosion>(ship.spawnExplosion()));
				ship.resetState();
			}
		}

		if (bulletReloadTimeLeft > 0) bulletReloadTimeLeft--;
		bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& bullet) { return !bullet.updateWithLifetime(); }), bullets.end());
		for (auto& asteroid : asteroids) asteroid.update();
		ship.updatePosition();

		animationsPtrs.erase(std::remove_if(animationsPtrs.begin(),
											animationsPtrs.end(),
											[](const std::unique_ptr<Animation>& animationPtr) { return !animationPtr->updateWithLifetime(); }),
							 animationsPtrs.end());

		windowPtr->clear();
		for (const auto& bullet : bullets) {
			bullet.draw(*windowPtr);
		}
		for (const auto& asteroid : asteroids) {
			asteroid.draw(*windowPtr);
		}
		for (const auto& animation : animationsPtrs) {
			animation->draw(*windowPtr);
		}
		ship.draw(*windowPtr);
		windowPtr->display();
	}
}

bool App::checkIfWindowInFocus() const {
	return windowPtr->getSystemHandle() == GetFocus();
}
