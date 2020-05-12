#include "Ship.h"

Ship::Ship() {
	position = { windowRightBorder / 2.0f, windowBottomBorder / 2.0f };

	sprite.setPosition(position);
	sprite.setPointCount(3);
	sprite.setPoint(0, { -20.0f, -12.0f });
	sprite.setPoint(1, { 20.0f, 0.0f });
	sprite.setPoint(2, { -20.0f, 12.0f });
	sprite.setFillColor({ 32, 64, 255 });
	sprite.setOutlineThickness(-3.0f);
}

void Ship::accelerate() {
	velocity += { static_cast<float>(acceleration*cos(rotation*M_PI / 180)), static_cast<float>(acceleration*sin(rotation*M_PI / 180)) };
	float speed = velocity.x*velocity.x + velocity.y*velocity.y;	// no sqrt because speed is only needed for comparison to speedLimit
	if (speed > speedLimit) {
		velocity = (speedLimit / speed)*velocity;
	}
}

void Ship::turnLeft() {
	rotateByAngle(-rotationSpeed);
}

void Ship::turnRight() {
	rotateByAngle(rotationSpeed);
}

Bullet Ship::spawnBullet() {
	return Bullet{ position, rotation };
}

void Ship::resetState() {
	position = { windowRightBorder / 2.0f, windowBottomBorder / 2.0f };
	velocity = { 0.0f, 0.0f };
	rotation = 0.0f;
	sprite.setPosition(position);
	sprite.setRotation(rotation);
}
