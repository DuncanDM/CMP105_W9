#include "DropManager.h" 

DropManager::DropManager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");
	noAlive = 0;

	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(50, 50));
	}
}

DropManager::~DropManager()
{

}

void DropManager::update(float dt, sf::Vector2u w)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}

	winSize = w;
	deathCheck();
}

void DropManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, rand() % 200 + 100);
			balls[i].setPosition(rand() % (winSize.x - 50), -50);
			noAlive++;
			return;
		}
	}
}

void DropManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > winSize.y + 100)
			{
				balls[i].setAlive(false);
				noAlive--;
			}
		}
	}
}

void DropManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}