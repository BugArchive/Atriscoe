#include "ShipExhaust.h"

ShipExhaust::ShipExhaust(const sf::Vector2f& position, float rotation) {
	sprite.setPosition(position);
	sprite.setPointCount(3);
	sprite.setPoint(0, { 6.0f, -10.4f });
	sprite.setPoint(1, { -12.0f, 0.0f });
	sprite.setPoint(2, { 6.0f, 10.4f });
	sprite.setRotation(rotation);
	sprite.setFillColor({ 64, 112, 255, static_cast<sf::Uint8>(20 * lifeTimeLeft) });
}

int ShipExhaust::updateWithLifetime() {
	lifeTimeLeft--;
	sprite.setFillColor({ 64, 112, 255, static_cast<sf::Uint8>(20 * lifeTimeLeft) });
	return lifeTimeLeft;
}

void ShipExhaust::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
