#pragma once
#include "Animation.h"
class ShipExplosion : public Animation {
public:
	ShipExplosion(const sf::Vector2f& position);
	int updateWithLifetime() override;
	void draw(sf::RenderWindow& window) const override;
private:
	sf::CircleShape sprite;
	static const int lifePeriod{ 120 };
	int lifeTimeLeft{ lifePeriod };
};
