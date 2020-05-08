#pragma once
#include <cmath>
#include <algorithm>
#include <SFML/Graphics.hpp>

constexpr float M_PI = 3.14159265358979323846f;

class GameElement {
public:
	void updatePosition();
	void rotateByAngle(float angle);
	bool checkIfCollidingWith(const GameElement& other) const;
	void draw(sf::RenderWindow& window) const;

protected:
	const static float windowRightBorder;
	const static float windowBottomBorder;

	sf::ConvexShape sprite;
	sf::Vector2f position{ 0.0f, 0.0f };
	sf::Vector2f velocity{ 0.0f, 0.0f };
	float rotation = 0.0f;

private:
	void wrapPosition();
	// Normal and Projection used for collision detection
	static sf::Vector2f calculateNormal(const sf::Vector2f& point1, const sf::Vector2f& point2, float rotationRadians);
	class Projection {
	public:
		Projection(const GameElement& gameElement, const sf::Vector2f& normal);
		constexpr bool checkIfOverlappingWith(const Projection& other) const;
	private:
		float lowestPoint, highestPoint;
	};
};
