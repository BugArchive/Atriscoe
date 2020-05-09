#pragma once
#include "GameElement.h"
class Bullet : public GameElement {
public:
	Bullet(const sf::Vector2f & position, float rotation);
	int updateWithLifetime();
private:
	static const float speed;
	int lifeTime{ 120 };
};

