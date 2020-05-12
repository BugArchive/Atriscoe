#include "ShipExplosion.h"

ShipExplosion::ShipExplosion(const sf::Vector2f & position) {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineThickness(3.0f);
	sprite.setPosition(position);
}

bool ShipExplosion::updateWithLifetime() {
	if (lifeTime > lifePeriod / 2) {
		sprite.setRadius(lifePeriod - lifeTime);
		sprite.setOrigin(lifePeriod - lifeTime, lifePeriod - lifeTime);
	}
	else {
		sprite.setRadius(lifeTime);
		sprite.setOrigin(lifeTime, lifeTime);
	}
	return --lifeTime;
}

void ShipExplosion::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
