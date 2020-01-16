#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Could not load font.\n";
	}

	// initialise game objects
	rect[0].setSize(sf::Vector2f(125, 125));
	rect[0].setPosition(100, 100);
	rect[0].setFillColor(sf::Color::Red);
	rect[1].setSize(sf::Vector2f(75, 75));
	rect[1].setPosition(125, 125);
	rect[1].setFillColor(sf::Color::Green);
	rect[2].setSize(sf::Vector2f(25, 25));
	rect[2].setPosition(150, 150);
	rect[2].setFillColor(sf::Color::Blue);
	rect[3].setSize(sf::Vector2f(50, 50));
	rect[3].setPosition(150, 150);
	rect[3].setFillColor(sf::Color::Green);

	sf::Vector2u windowSize = window->getSize();

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(windowSize.x / 2, 0);

	circle.setRadius(50.0f);
	circle.setPosition(windowSize.x/2 - 25, windowSize.y/2 - 25);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.0f);

}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{

	sf::Vector2u windowSize = window->getSize();
	rect[3].setPosition(windowSize.x - 25, windowSize.y - 25);
	
}

// Render level
void Level::render()
{
	beginDraw();

	for (int i = 0; i < 4; i++) {
		window->draw(rect[i]);
	}

	window->draw(circle);
	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}