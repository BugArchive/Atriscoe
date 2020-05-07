#include "GameElement.h"

const float GameElement::windowRightBorder = static_cast<float>(sf::VideoMode::getDesktopMode().width);
const float GameElement::windowBottomBorder = static_cast<float>(sf::VideoMode::getDesktopMode().height);

void GameElement::updatePosition() {
	position += velocity;
	wrapPosition();
	sprite.setPosition(position);
}

void GameElement::rotateByAngle(float angle) {
	rotation = fmod(rotation + angle, 360.0f);
	sprite.setRotation(rotation);
}

void GameElement::draw(sf::RenderWindow& window) const {
	window.draw(sprite);
}

void GameElement::wrapPosition() {
	sf::FloatRect frame = sprite.getGlobalBounds();
	if (position.x < -frame.width / 2) {
		position.x = windowRightBorder + frame.width / 2;
	}
	else if (position.x > windowRightBorder + frame.width / 2) {
		position.x = -frame.width / 2;
	}
	if (position.y < -frame.height / 2) {
		position.y = windowBottomBorder + frame.height / 2;
	}
	else if (position.y > windowBottomBorder + frame.height / 2) {
		position.y = -frame.height / 2;
	}
}