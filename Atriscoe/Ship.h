#pragma once
#include "GameElement.h"

class Ship : public GameElement {
public:
	Ship();
	void accelerate();
	void turnLeft();
	void turnRight();
private:
	const float speedLimit = 400.0f;
	const float acceleration = 0.2f;
	const float rotationSpeed = 4.0f;
};

