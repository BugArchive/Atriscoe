#pragma once
#include <SFML/Graphics.hpp>
class ShipExplosion {
public:
	ShipExplosion(const sf::Vector2f& position);
	bool updateWithLifetime();
	void draw(sf::RenderWindow& window) const;
private:
	sf::CircleShape sprite;
	static const int lifePeriod{ 120 };
	int lifeTime{ lifePeriod };
};

