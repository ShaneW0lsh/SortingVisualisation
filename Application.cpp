#include "Application.h"

//Constructor & Destructor
Application::Application(int width, int height, int FramerateLimit, int size)
{
	this->init_window(width, height, FramerateLimit);
	this->init_variables(size);

	//this->window->clear(sf::Color(96, 96, 96));
	this->data.show();
	//this->window->display();
}

Application::~Application() { delete this->window; }
//===================================================

//Variable initialization
void Application::init_window(int width, int height, int FramerateLimit)
{
	this->contextSettings.antialiasingLevel = 8;
	this->vm.width = width;
	this->vm.height = height;
	this->window = new sf::RenderWindow(vm, "Sorting Visualization", sf::Style::None, this->contextSettings);
	this->window->setFramerateLimit(FramerateLimit);
}

void Application::init_variables(int size)
{
	this->data.init_window(this->window, this->vm.width, this->vm.height);
	this->data.init_array(size);
}
//===================================================

//Accessors and Setters 
bool Application::running() { return this->window->isOpen(); }
//===================================================
//NOTE: I SHOULD RENDER EVERYTHING IN THE SORTING ALGO ITSELF
//ADD: UPDATE_DATA

void Application::run()
{
	while (this->running())
	{
		this->update();
	}
}

void Application::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();

                if (this->ev.key.code == sf::Keyboard::S)
                    this->data.shuffle();

                if (this->ev.key.code == sf::Keyboard::B)
                    this->data.bubble_sort();

                if (this->ev.key.code == sf::Keyboard::Q)
                    this->data.quick_sort();
                break;
		}
	}
}

void Application::update()
{
	this->pollEvents();
}
