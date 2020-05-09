#include "Asteroid.h"

Asteroid::Asteroid(const sf::Vector2f& position) : rotationSpeed(randFloat(-1.0f, 1.0f)) {
	this->position = position;
	velocity = { randFloat(-3.0f, 3.0f), randFloat(-3.0f, 3.0f) };

	float sprite_size = 16.0f;
	sprite.setPointCount(4);
	sprite.setPoint(0, sprite_size*sf::Vector2f{ -7.5f, -7.5f });
	sprite.setPoint(1, sprite_size*sf::Vector2f{ 7.5f, -7.5f });
	sprite.setPoint(2, sprite_size*sf::Vector2f{ 7.5f, 7.5f });
	sprite.setPoint(3, sprite_size*sf::Vector2f{ -7.5f, 7.5f });
	sprite.setFillColor({ 60, 40, 30 });
	sprite.setOutlineThickness(-3.0f);
}

void Asteroid::update() {
	rotateByAngle(rotationSpeed);
	updatePosition();
}
