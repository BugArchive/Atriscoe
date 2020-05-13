#pragma once
#include <SFML/Graphics.hpp>
class Animation {
public:
	virtual int updateWithLifetime() = 0;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual ~Animation() = default;
};
