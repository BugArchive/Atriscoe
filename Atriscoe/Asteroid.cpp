#include "Asteroid.h"

Asteroid::Asteroid(const sf::Vector2f& position) : rotationSpeed(randFloat(-1.0f, 1.0f)) {
	this->position = position;
	velocity = { randFloat(-3.0f, 3.0f), randFloat(-3.0f, 3.0f) };

	float sprite_size = 16.0f;
	sprite.setPosition(position);
	sprite.setFillColor({ 60, 40, 30 });
	sprite.setOutlineThickness(-3.0f);

	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> dis(3, 5);
	int random_number = dis(gen);
	switch (random_number) {
	case 3:
		sprite.setPointCount(3);
		sprite.setPoint(0, sprite_size*sf::Vector2f(-6.0f, -10.4f));
		sprite.setPoint(1, sprite_size*sf::Vector2f(12.0f, 0.0f));
		sprite.setPoint(2, sprite_size*sf::Vector2f(-6.0f, 10.4f));
		break;
	case 4:
		sprite.setPointCount(4);
		sprite.setPoint(0, sprite_size*sf::Vector2f{ -7.5f, -7.5f });
		sprite.setPoint(1, sprite_size*sf::Vector2f{ 7.5f, -7.5f });
		sprite.setPoint(2, sprite_size*sf::Vector2f{ 7.5f, 7.5f });
		sprite.setPoint(3, sprite_size*sf::Vector2f{ -7.5f, 7.5f });
		break;
	case 5:
		sprite.setPointCount(5);
		sprite.setPoint(0, sprite_size*sf::Vector2f(-7.5f, -6.0f));
		sprite.setPoint(1, sprite_size*sf::Vector2f(3.0f, -9.0f));
		sprite.setPoint(2, sprite_size*sf::Vector2f(9.0f, 0.0f));
		sprite.setPoint(3, sprite_size*sf::Vector2f(3.0f, 9.0f));
		sprite.setPoint(4, sprite_size*sf::Vector2f(-7.5f, 6.0f));
		break;
	}
}

void Asteroid::update() {
	rotateByAngle(rotationSpeed);
	updatePosition();
}

AsteroidExplosion Asteroid::spawnExplosion() const {
	return AsteroidExplosion(sprite);
}
