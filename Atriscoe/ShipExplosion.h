#pragma once
#include <SFML/Graphics.hpp>
class ShipExplosion {
public:
	ShipExplosion(const sf::Vector2f& position);
	int updateWithLifetime();
	void draw(sf::RenderWindow& window) const;
private:
	sf::CircleShape sprite;
	static const int lifePeriod{ 120 };
	int lifeTimeLeft{ lifePeriod };
};

