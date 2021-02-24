#include "Snake_game.h"




void game_list::write_record(int score)
{
}

void game_manager::perform_game_session(SDL_Window* window, SDL_Renderer* renderer)
{
	//create window and renderer
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//init
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << " Error!!! \n", SDL_GetError();
	}

	//add background
	SDL_Surface* background = IMG_Load("background.png");
	SDL_Texture* backgroung_texture;
	backgroung_texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderCopy(renderer, backgroung_texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_FreeSurface(background);
	SDL_DestroyTexture(backgroung_texture);
	backgroung_texture = NULL;
	
	//fill field empty blocks
	field field;
	field.fill_field();

}



void game_manager::clean_memmory()
{
	
}



void fruit::replace_fruit()
{
	
		int x, y;
		while (1)
		{
			x = rand() % BLOCK_WIDTH;
			y = rand() % BLOCK_HEIGHT;

			if (block[x][y] == Block::empty)
			{
				block[x][y] = Block::fruit;
				fruit.x = x;
				fruit.y = y;
				break;
			}
		}
	
}

void field::fill_field()
{
	for (int i = 0; i < BLOCK_WIDTH; ++i)
		for (int j = 0; j < BLOCK_HEIGHT; ++j)
		{
			block[i][j] = Block::empty;
		}
}

int snake::grow_snake(int size)
{
	snake_size += size;
	return 0;
}

void snake::Moves()
{

	SDL_Event e;
	    while (SDL_PollEvent(&e))
	    {
	        if (e.type == SDL_QUIT)
	        {
	           quit = false;
	        }
	        else if (e.type == SDL_KEYDOWN)
	        {
	            switch (e.key.keysym.sym)
	            {
	            case SDLK_UP:
	                if (last_direction != Move::down || snake_size == 1)
	                    direction = Move::up;
	                break;
	
	            case SDLK_DOWN:
	                if (last_direction != Move::up || snake_size == 1)
	                    direction = Move::down;
	                break;
	
	            case SDLK_LEFT:
	                if (last_direction != Move::right || snake_size == 1)
	                    direction = Move::left;
	                break;
	
	            case SDLK_RIGHT:
	                if (last_direction != Move::left || snake_size == 1)
	                    direction = Move::right;
	                break;
	            }
	        }
	    }
}
