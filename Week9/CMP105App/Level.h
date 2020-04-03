#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "BallManager.h"
#include "DropManager.h"
#include "Player.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	BallManager ballManager;

	DropManager dropManager;

	Player player;
	sf::Texture texture;

	sf::Vector2u winSize;
	sf::Vector2f winCentre;

	sf::Font font;
	sf::Text text;
};