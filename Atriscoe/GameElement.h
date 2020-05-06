#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // M_PI

class GameElement {
public:
	void updatePosition();
	void rotateByAngle(float angle);

protected:
	const static float windowRightBorder;
	const static float windowBottomBorder;

	sf::ConvexShape sprite;
	sf::Vector2f position{ 0.0f, 0.0f };
	sf::Vector2f velocity{ 0.0f, 0.0f };
	float rotation = 0.0f;

private:
	void wrapPosition();
};

