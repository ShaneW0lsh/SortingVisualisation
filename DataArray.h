#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

#include <SFML/Graphics.hpp>

class DataArray
{
private:
	sf::RenderWindow* window;
	sf::VideoMode vm;

	int size;
	int m_size;
	float diff;
	float bar_width;
	std::vector<float> values;
	std::vector<unsigned int> states;

	/*Private Functions*/
	void init_variables();

	void mark(int idx, int state_);
	void mark(int first_idx, int second_idx, int state_);
public:
	/*Constructors/Destructors*/
	DataArray();

	/*Public Functions*/
	void init_window(sf::RenderWindow* window_, int width_, int height_);
	void init_array(int size_);
	void shuffle();

	bool check_sorted();

	void swap(int first_idx, int second_idx);
	void show();

	/*Algorithms*/
	void bubble_sort();
	void quick_sort();
	void quick_sort(std::vector<float>& array);

	/*Algo Utility*/
	void partition(std::vector<float>& less, std::vector<float>& greater, float pivot_val);
};