#pragma once
#include "Animation.h"
class ShipExhaust : public Animation {
public:
	ShipExhaust(const sf::Vector2f& position, float rotation);
	int updateWithLifetime() override;
	void draw(sf::RenderWindow& window) const override;
private:
	sf::ConvexShape sprite;
	int lifeTimeLeft{ 10 };
};
