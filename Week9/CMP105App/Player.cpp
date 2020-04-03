#include "Player.h" 

Player::Player()
{
	texture.loadFromFile("gfx/Beach_Ball.png");
	speed = 500.f;
	bulletSpd = 250.f;
	timer = 0;

	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(25, 25));
	}
}

Player::~Player()
{

}

void Player::setVelocity(float dt)
{
	sf::Vector2f target = sf::Vector2f(input->getMouseX(), input->getMouseY());
	sf::Vector2f direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity = (direction * bulletSpd);
}

void Player::handleInput(float dt)
{
	timer += dt;

	if (input->isKeyDown(sf::Keyboard::W))
	{
		move(0 , -speed * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		move(0, speed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(speed * dt, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		move(-speed * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Space) && timer >= 0.5f)
	{
		input->setKeyUp(sf::Keyboard::Space);
		setVelocity(dt);
		timer = 0;
		spawn();
	}
}

void Player::update(float dt, sf::Vector2u w)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}

	ballSize = balls.size();

	winSize = w;
	deathCheck();
}

void Player::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(velocity);
			balls[i].setPosition(getPosition());
			return;
		}
	}
}

void Player::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > winSize.x + 100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > winSize.y + 100)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void Player::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}