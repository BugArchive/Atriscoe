#pragma once
#include <random>
#include "RandomFloatGenerator.h"
#include "GameElement.h"
#include "AsteroidExplosion.h"

class Asteroid : public GameElement {
public:
	Asteroid(const sf::Vector2f& position = { randFloat(0.0f, windowRightBorder), randFloat(0.0f, windowBottomBorder) }, int size = 4);
	void update();
	AsteroidExplosion spawnExplosion() const;
	const sf::Vector2f& getPosition() const;
	int getSize() const;
private:
	static constexpr auto randFloat = RandomFloatGenerator::generateRandomFloatInRange;
	int size;
	float rotationSpeed;
};
