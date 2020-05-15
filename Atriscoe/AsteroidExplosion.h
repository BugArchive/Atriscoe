#pragma once
#include "Animation.h"
class AsteroidExplosion : public Animation {
public:
	AsteroidExplosion(const sf::ConvexShape& sprite);
	int updateWithLifetime() override;
	void draw(sf::RenderWindow& window) const override;
private:
	sf::ConvexShape sprite;
	int lifeTimeLeft{ 60 };
};
