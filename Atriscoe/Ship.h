#pragma once
#include "GameElement.h"
#include "Bullet.h"
#include "ShipExhaust.h"
#include "ShipExplosion.h"

class Ship : public GameElement {
public:
	Ship();
	void accelerate();
	void turnLeft();
	void turnRight();
	Bullet spawnBullet();
	ShipExhaust spawnExhaust();
	ShipExplosion spawnExplosion();
	void resetState();
private:
	const float speedLimit{ 256.0f };
	const float acceleration{ 0.2f };
	const float rotationSpeed{ 4.0f };
};
