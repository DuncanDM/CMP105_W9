#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Balls Alive: ");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition(0, 0);

	player.setInput(input);

	winSize = window->getSize();
	winCentre = sf::Vector2f(winSize.x / 2 - player.getSize().x, winSize.y / 2 - player.getSize().y);

	texture.loadFromFile("gfx/MushroomTrans.png");
	player.setSize(sf::Vector2f(50, 50));
	player.setPosition(winCentre);
	player.setTexture(&texture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//if (input->isKeyDown(sf::Keyboard::S))
	//{
	//	input->setKeyUp(sf::Keyboard::S);
	//	ballManager.spawn();
	//}

	//if (input->isKeyDown(sf::Keyboard::S))
	//{
	//	input->setKeyUp(sf::Keyboard::S);
	//	dropManager.spawn();
	//}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	winSize = window->getSize();

	//ballManager.update(dt, winSize);

	//std::string output("Balls Alive: " + std::to_string(ballManager.noAlive));
	//text.setString(output);

	//dropManager.update(dt, winSize);

	std::string output("Balls Alive: " + std::to_string(player.ballSize));
	text.setString(output);

	player.update(dt, winSize);
}

// Render level
void Level::render()
{
	beginDraw();

	//ballManager.render(window);

	//dropManager.render(window);

	window->draw(text);

	window->draw(player);
	player.render(window);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}