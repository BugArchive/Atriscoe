#pragma once
#include "GameElement.h"
#include "Bullet.h"

class Ship : public GameElement {
public:
	Ship();
	void accelerate();
	void turnLeft();
	void turnRight();
	Bullet spawnBullet();
private:
	const float speedLimit{ 256.0f };
	const float acceleration{ 0.2f };
	const float rotationSpeed{ 4.0f };
};
