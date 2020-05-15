#pragma once
#include "RandomFloatGenerator.h"
#include "GameElement.h"
#include "AsteroidExplosion.h"

class Asteroid : public GameElement {
public:
	Asteroid(const sf::Vector2f& position = { randFloat(0.0f, windowRightBorder), randFloat(0.0f, windowBottomBorder) });
	void update();
	AsteroidExplosion spawnExplosion() const;

private:
	static constexpr auto randFloat = RandomFloatGenerator::generateRandomFloatInRange;
	float rotationSpeed;
};
