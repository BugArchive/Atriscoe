#include "Asteroid.h"

Asteroid::Asteroid() {
	position = {200.0f, 300.0f};
	velocity = { 1.0f, 2.0f };

	float sprite_size = 16.0f;
	sprite.setPointCount(4);
	sprite.setPoint(0, sprite_size*sf::Vector2f(-7.5f, -7.5f));
	sprite.setPoint(1, sprite_size*sf::Vector2f(7.5f, -7.5f));
	sprite.setPoint(2, sprite_size*sf::Vector2f(7.5f, 7.5f));
	sprite.setPoint(3, sprite_size*sf::Vector2f(-7.5f, 7.5f));
	sprite.setFillColor(sf::Color(60, 40, 30));
	sprite.setOutlineThickness(3.0f);
}
