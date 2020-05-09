#pragma once
#include "RandomFloatGenerator.h"
#include "GameElement.h"

class Asteroid : public GameElement {
public:
	Asteroid(const sf::Vector2f& position = { randFloat(0.0f, windowRightBorder), randFloat(0.0f, windowBottomBorder) });
	void update();
private:
	static constexpr auto randFloat = RandomFloatGenerator::generateRandomFloatInRange;
	float rotationSpeed;
};

