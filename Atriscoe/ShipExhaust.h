#pragma once
#include <SFML/Graphics.hpp>
class ShipExhaust {
public:
	ShipExhaust(const sf::Vector2f& position, float rotation);
	int updateWithLifetime();
	void draw(sf::RenderWindow& window) const;
private:
	sf::ConvexShape sprite;
	int lifeTimeLeft{ 10 };
};
