#include "AsteroidExplosion.h"

AsteroidExplosion::AsteroidExplosion(const sf::ConvexShape & baseSprite) : sprite(baseSprite) {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor({ 200, 200, 200, static_cast<sf::Uint8>(3 * lifeTimeLeft) });
}

int AsteroidExplosion::updateWithLifetime() {
	lifeTimeLeft--;
	int pointCount = static_cast<int>(sprite.getPointCount());
	for (int i = 0; i < pointCount; i++) {
		sprite.setPoint(i, sprite.getPoint(i)*1.02f);
	}
	sprite.setOutlineColor({ 200, 200, 200, static_cast<sf::Uint8>(4 * lifeTimeLeft) });
	return lifeTimeLeft;
}

void AsteroidExplosion::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
