#pragma once

#pragma once

#include "Ball.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <math.h>
#include <vector>

class Player : public GameObject
{
public:
	Player();
	~Player();

	void spawn();
	void update(float dt, sf::Vector2u w);
	void handleInput(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	void setVelocity(float dt);

	int ballSize;

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Vector2u winSize;
	sf::Vector2f velocity;
	float speed;
	float bulletSpd;
	float timer;
};