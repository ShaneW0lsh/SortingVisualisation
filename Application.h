#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "DataArray.h"

#include "iostream"


class Application
{
private:
	sf::RenderWindow* window;
	sf::VideoMode vm;
	sf::Event ev;
	sf::ContextSettings contextSettings;

	void init_window(int width, int heigth, int FramerateLimit);
	void init_variables(int size);

	DataArray data;

	bool running();

public:
	Application(int width, int height, int FramerateLimit, int size);
	~Application();

	void run();
	void pollEvents();
	void update();
};
