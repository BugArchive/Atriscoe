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

bool GameElement::checkIfCollidingWith(const GameElement & other) const {
	// collision detection is done by checking overlaps of projections
	// GameElements are projected on the normals of every edge of both elements
	// taking this element and checking all edges then swapping and checking all edges of the other element
	// any separation of projections means separation of the elements in 2D space
	// lack of separation for all projections means overlap of elements in 2D space
	auto currentElement = this;
	while (true) {
		int point_count = static_cast<int>(currentElement->sprite.getPointCount());
		float rotation_radians = currentElement->sprite.getRotation()*M_PI / 180;
		for (int i = 0; i < point_count; i++) {
			auto normal = calculateNormal(
				currentElement->sprite.getPoint(i),
				currentElement->sprite.getPoint(i + 1 < point_count ? i + 1 : 0),
				rotation_radians);
			Projection projection1{ *this, normal };
			Projection projection2{ other, normal };
			if (!projection1.checkIfOverlappingWith(projection2)) {
				// projection separation signals lack of collision
				return false;
			}
		}
		if (currentElement == &other) {
			break;
		}
		currentElement = &other;
	}
	return true;
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

sf::Vector2f GameElement::calculateNormal(const sf::Vector2f & point1, const sf::Vector2f & point2, float rotationRadians) {
	sf::Vector2f true_point1 = sf::Vector2f(
		point1.x*cos(rotationRadians) - point1.y*sin(rotationRadians),
		point1.x*sin(rotationRadians) + point1.y*cos(rotationRadians));

	sf::Vector2f true_point2 = sf::Vector2f(
		point2.x*cos(rotationRadians) - point2.y*sin(rotationRadians),
		point2.x*sin(rotationRadians) + point2.y*cos(rotationRadians));
	return sf::Vector2f(true_point1.y - true_point2.y, true_point2.x - true_point1.x);
}

GameElement::Projection::Projection(const GameElement & gameElement, const sf::Vector2f & normal) {
	// Every vertex of gameElement's sprite is projected onto the normal
	// the values of the lowest and highest points of the projection are stored in the Projection object

	int vertex_count = static_cast<int>(gameElement.sprite.getPointCount());
	float rotation_radians = gameElement.sprite.getRotation()*M_PI / 180;

	// calculating vertex global position
	sf::Vector2f global_vertex_position = gameElement.position + sf::Vector2f(
		gameElement.sprite.getPoint(0).x*cos(rotation_radians) - gameElement.sprite.getPoint(0).y*sin(rotation_radians),
		gameElement.sprite.getPoint(0).x*sin(rotation_radians) + gameElement.sprite.getPoint(0).y*cos(rotation_radians));

	highestPoint = lowestPoint = global_vertex_position.x*normal.x + global_vertex_position.y*normal.y;

	for (int i = 1; i < vertex_count; i++) {
		global_vertex_position = gameElement.position + sf::Vector2f(
			gameElement.sprite.getPoint(i).x*cos(rotation_radians) - gameElement.sprite.getPoint(i).y*sin(rotation_radians),
			gameElement.sprite.getPoint(i).x*sin(rotation_radians) + gameElement.sprite.getPoint(i).y*cos(rotation_radians));

		float point_projection_value = global_vertex_position.x*normal.x + global_vertex_position.y*normal.y;

		lowestPoint = std::min(lowestPoint, point_projection_value);
		highestPoint = std::max(highestPoint, point_projection_value);
	}
}

constexpr bool GameElement::Projection::checkIfOverlappingWith(const Projection & other) const {
	if (lowestPoint >= other.lowestPoint && lowestPoint <= other.highestPoint) {
		return true;
	}
	if (other.lowestPoint >= lowestPoint && other.lowestPoint <= highestPoint) {
		return true;
	}
	// checking if either one's lowestPoint is contained within another one's projection fully checks possible overlap
	return false;
}
