#include "Snake_game.h"





void map::create_window(SDL_Window* window)
{
	
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//init
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << " Error!!! \n", SDL_GetError();
	}


}

void map::load_media()
{
}

void map::clean_memmory()
{
}


void fruit::render_fruit(int x, int y)
{

}

void fruit::clean_memmory()
{
}

void game_list::write_record(int score)
{
}
