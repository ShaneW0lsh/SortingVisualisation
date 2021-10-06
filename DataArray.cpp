#include "DataArray.h"

DataArray::DataArray() {}

void DataArray::init_window(sf::RenderWindow* window_, int width_, int height_)
{
	this->window = window_;
	this->vm.width = width_;
	this->vm.height = height_;
}

/*Private Functions*/
void DataArray::init_variables()
{
	this->bar_width = this->vm.width / this->size;
	this->diff = (this->values[this->size-1] - this->values[0]) / (this->size-1);

	this->states = std::vector<unsigned int>(this->size, 0);
}

void DataArray::mark(int idx, int state_)
{
	this->states[idx] = state_;
}

void DataArray::mark(int first_idx, int second_idx, int state_)
{
	this->states[first_idx] = state_;
	this->states[second_idx] = state_;
}

/*Public Functions*/
void DataArray::init_array(int size_)
{
	this->size = size_;
	this->values.resize(this->size);
	this->values[size-1] = this->vm.height-10;
	this->values[0] = this->values[size-1] / this->size;

	this->init_variables();

	for (int i = 1; i < this->size-1; i++) {
		this->values[i] = this->values[i-1] + this->diff;
	}
}

void DataArray::shuffle()
{
	for (int i = 0; i < 10; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		random_shuffle(this->values.begin(), this->values.end());
		this->show();
	}
}

bool DataArray::check_sorted()
{
	for (int i = 0; i < this->size; i++) {
		if (i != this->size - 1) {
			if (this->values[i] > this->values[i + 1])
				return false;

			else {
				this->mark(i, 3);
				this->show();
			}
		}
		else {
			this->mark(i, 3);
			this->show();
			for (int i = 0; i < this->size; i++) {
				this->mark(i, 0);
			}
			this->show();
		}
	}
	return true;
}

void DataArray::swap(int first_idx, int second_idx)
{
	int temp;
	temp = this->values[first_idx];
	this->values[first_idx] = this->values[second_idx];
	this->values[second_idx] = temp;

	this->show();
}

void DataArray::show()
{
	this->window->clear(sf::Color(96, 96, 96));

	for (int i = 0; i < this->size; i++) 
	{
		sf::Vector2f size(this->bar_width, this->values[i]);
		sf::RectangleShape bar(size);

		bar.setPosition(bar_width*i, this->vm.height-values[i]);

		switch(this->states[i]) {
			case 0:
				bar.setFillColor(sf::Color::White);
				break;
			case 1:
				bar.setFillColor(sf::Color::Red);
				break;
			case 2:
				bar.setFillColor(sf::Color::Blue);
				break;
			case 3:
				bar.setFillColor(sf::Color::Green);
				break;
		}
		
		bar.setOutlineColor(sf::Color::Black);
		bar.setOutlineThickness(1);

		this->window->draw(bar);
	}	

	this->window->display();
}


/*Algorithms*/
void DataArray::bubble_sort()
{
	if (!this->check_sorted()) {
		for (int j = 0; j < this->size-1; j++) {
			for (int i = 0; i < this->size - j - 1; i++) {
				this->mark(i, i + 1, 1);

				if (this->values[i] > this->values[i + 1]) {
					this->swap(i, i + 1);
				}
				this->show();
				this->mark(i, i + 1, 0);
			}
		}
		this->check_sorted();
	}
}

void DataArray::partition(std::vector<float>& less, std::vector<float>& greater, float pivot_val)
{
	for (int i = 0; i < this->size; i++) {
		if (this->values[i] < pivot_val)
			less.push_back(this->values[i]);
		else if (this->values[i] > pivot_val)
			greater.push_back(this->values[i]);
	}
}

void DataArray::quick_sort(int start, int end)
{
	if (low >= high) return;

	int pivot_idx = partition(start, end);
}
