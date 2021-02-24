#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const int BLOCK_WIDTH = 32;
const int BLOCK_HEIGHT = 32;

static bool quit = true;
//blocks
enum class Block { head, body, fruit, empty };
static Block block[BLOCK_WIDTH][BLOCK_HEIGHT];

//moves
enum class Move { up, down, left, right };
//first direction/move

static Move last_direction = Move::down;
static Move direction = Move::down;
class game_manager
{


public:
	void perform_game_session(SDL_Window* window, SDL_Renderer* renderer);

	void clean_memmory();


};


class fruit {
	SDL_Point fruit;
public:

	void replace_fruit();

};

class field {

public:
	void fill_field();
};

class snake
{
	int snake_size=1;
	int grow_snake(int size);
	void Moves();
};



class game_list
{
	std::pair<std::string, int> record;
public:
	void write_record(int score);
};
