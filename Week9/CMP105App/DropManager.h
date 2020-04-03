#pragma once

#include "Ball.h"
#include <math.h>
#include <vector>

class DropManager
{
public:
	DropManager();
	~DropManager();

	void spawn();
	void update(float dt, sf::Vector2u w);
	void deathCheck();
	void render(sf::RenderWindow* window);

	int noAlive;

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Vector2u winSize;
};
