#pragma once
#include <string>
#include <SDL.h>
#include <iostream>



class Snake_game
{


public:



};

class map {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 640;

public:

	void create_window(SDL_Window* window);
	void load_media();
	void clean_memmory();
};

class fruit
{
	const int FRUIT_WIDTH = 32;
	const int FRUIT_HEIGHT = 32;
public:
	void render_fruit(int x, int y);
	void clean_memmory();
};

class snake
{


};

class game_list 
{
	std::pair<std::string,int> record;
public:
	void write_record(int score);
};
