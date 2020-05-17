#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "AppScreen.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Animation.h"
#include "ShipExhaust.h"
#include "ShipExplosion.h"
#include "AsteroidExplosion.h"

class Game : public AppScreen {
public:
	Game();
	void handleControls() override;
	void update() override;
	void draw(sf::RenderWindow& window) const override;
private:
	Ship ship;
	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;
	std::vector<std::unique_ptr<Animation>> animationsPtrs;
	const int bulletReloadPeriod{ 60 };
	int bulletReloadTimeLeft{ 30 };
};
