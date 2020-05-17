#include "Game.h"

Game::Game() {
	asteroids.emplace_back(Asteroid());
	asteroids.emplace_back(Asteroid());
}

void Game::handleControls() {
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

void Game::update() {

	// check GameElements' collisions
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

	// update GameElements' states
	ship.updatePosition();
	for (auto& asteroid : asteroids) asteroid.update();
	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& bullet) { return !bullet.updateWithLifetime(); }), bullets.end());
	animationsPtrs.erase(std::remove_if(animationsPtrs.begin(),
										animationsPtrs.end(),
										[](const std::unique_ptr<Animation>& animationPtr) { return !animationPtr->updateWithLifetime(); }),
						 animationsPtrs.end());

	if (bulletReloadTimeLeft > 0) bulletReloadTimeLeft--;
}

void Game::draw(sf::RenderWindow & window) const {
	for (const auto& bullet : bullets) {
		bullet.draw(window);
	}
	for (const auto& asteroid : asteroids) {
		asteroid.draw(window);
	}
	for (const auto& animation : animationsPtrs) {
		animation->draw(window);
	}
	ship.draw(window);
}
