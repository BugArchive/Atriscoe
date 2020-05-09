#include "Bullet.h"

const float Bullet::speed = 10.0f;

Bullet::Bullet(const sf::Vector2f & position, float rotation) {
	this->position = position;
	velocity = { speed*cos(rotation*M_PI / 180), speed*sin(rotation*M_PI / 180) };

	sprite.setPosition(position);
	sprite.setPointCount(3);
	sprite.setPoint(0, { -10.0f, -5.0f });
	sprite.setPoint(1, { 10.0f, 0.0f });
	sprite.setPoint(2, { -10.0f, 5.0f });
	sprite.setRotation(rotation);
	sprite.setOutlineThickness(-2.0f);
	sprite.setFillColor(sf::Color::Transparent);
}

int Bullet::updateWithLifetime() {
	updatePosition();
	return --lifeTime;
}
