#include "ShipExplosion.h"

ShipExplosion::ShipExplosion(const sf::Vector2f & position) {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineThickness(3.0f);
	sprite.setPosition(position);
}

int ShipExplosion::updateWithLifetime() {
	if (lifeTimeLeft > lifePeriod / 2) {
		sprite.setRadius(static_cast<float>(lifePeriod - lifeTimeLeft));
		sprite.setOrigin(static_cast<float>(lifePeriod - lifeTimeLeft), static_cast<float>(lifePeriod - lifeTimeLeft));
	}
	else {
		sprite.setRadius(static_cast<float>(lifeTimeLeft));
		sprite.setOrigin(static_cast<float>(lifeTimeLeft), static_cast<float>(lifeTimeLeft));
	}
	return --lifeTimeLeft;
}

void ShipExplosion::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
