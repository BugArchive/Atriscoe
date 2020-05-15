#include "Asteroid.h"

Asteroid::Asteroid(const sf::Vector2f& position, int size) : size(size), rotationSpeed(randFloat(-1.0f, 1.0f)) {
	this->position = position;
	velocity = { randFloat(-3.0f, 3.0f), randFloat(-3.0f, 3.0f) };

	float sprite_size = static_cast<float>(size);
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
		sprite.setPoint(0, sprite_size*sf::Vector2f(-24.0f, -41.6f));
		sprite.setPoint(1, sprite_size*sf::Vector2f(48.0f, 0.0f));
		sprite.setPoint(2, sprite_size*sf::Vector2f(-24.0f, 41.6f));
		break;
	case 4:
		sprite.setPointCount(4);
		sprite.setPoint(0, sprite_size*sf::Vector2f{ -30.0f, -30.0f });
		sprite.setPoint(1, sprite_size*sf::Vector2f{ 30.0f, -30.0f });
		sprite.setPoint(2, sprite_size*sf::Vector2f{ 30.0f, 30.0f });
		sprite.setPoint(3, sprite_size*sf::Vector2f{ -30.0f, 30.0f });
		break;
	case 5:
		sprite.setPointCount(5);
		sprite.setPoint(0, sprite_size*sf::Vector2f(-30.0f, -24.0f));
		sprite.setPoint(1, sprite_size*sf::Vector2f(12.0f, -36.0f));
		sprite.setPoint(2, sprite_size*sf::Vector2f(36.0f, 0.0f));
		sprite.setPoint(3, sprite_size*sf::Vector2f(12.0f, 36.0f));
		sprite.setPoint(4, sprite_size*sf::Vector2f(-30.0f, 24.0f));
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

const sf::Vector2f & Asteroid::getPosition() const {
	return position;
}

int Asteroid::getSize() const {
	return size;
}
