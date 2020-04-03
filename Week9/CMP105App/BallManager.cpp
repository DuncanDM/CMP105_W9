#include "BallManager.h" 

BallManager::BallManager()
{
	spawnPoint=sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	noAlive = 0;
	
	for(int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BallManager::~BallManager()
{

}

void BallManager::update(float dt, sf::Vector2u w)
{
	for(int i = 0; i < balls.size(); i++)
	{
		if(balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	
	winSize = w;
	deathCheck();
}

void BallManager::spawn() 
{
	for (int i = 0; i < balls.size(); i++)
	{ 
		if (!balls[i].isAlive()) 
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			noAlive++;
			return; 
		} 
		else if (i == balls.size() - 1)
		{
			balls.push_back(Ball());
			balls[i].setTexture(&texture);
			balls[i].setSize(sf::Vector2f(100, 100));
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			noAlive++;
			return;
		}
	} 
}

void BallManager::deathCheck() 
{
	for (int i = 0; i < balls.size(); i++)
	{ 
		if (balls[i].isAlive()) 
		{
			if (balls[i].getPosition().x < -100) 
			{ 
				balls[i].setAlive(false);
				noAlive--;
			}
			if (balls[i].getPosition().x > winSize.x + 100) 
			{ 
				balls[i].setAlive(false); 
				noAlive--;
			}
			if (balls[i].getPosition().y < -100)
			{ 
				balls[i].setAlive(false); 
				noAlive--;
			}
			if (balls[i].getPosition().y > winSize.y + 100) 
			{ 
				balls[i].setAlive(false); 
				noAlive--;
			} 
		} 
	} 
}

void BallManager::render(sf::RenderWindow* window) 
{ 
	for (int i = 0; i < balls.size(); i++) 
	{ 
		if (balls[i].isAlive()) 
		{ 
			window->draw(balls[i]); 
		} 
	} 
}