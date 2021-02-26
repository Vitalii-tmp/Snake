#include "Snake_game.h"
#include "Interfase.h"
#include <conio.h>
#pragma once




// constants of screen, field and block size
//const int SCREEN_WIDTH = 864;
//const int SCREEN_HEIGHT = 464;
//const int FIELD_WIDTH = 800;
//const int FIELD_HEIGHT = 400;
//const int BLOCK_WIDTH = 16;
//const int BLOCK_HEIGHT = 16;
//
////windiw and renderer
//SDL_Renderer* renderer = nullptr;
//SDL_Window* Window = nullptr;
//
////coordinates of head and fruit
//int headX, headY;
//int fruitX, fruitY;
//
////score (how match snake eat)
//int score;
//bool game_over = false;
//
////enumeration of directions
//enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
//Direction dir;
//Direction last_dir;
//
////arrays whitch save coordinates tail
//int tailX[1250];
//int tailY[1250];
//
////lenth of tail
//int lenth_of_tail=0;



//game manager
void game_manager::Setup()
{
	//create window and renderer
	Window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);


	//init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << " Error!!! \n", SDL_GetError();
	}
	//init ttf
	TTF_Init();

	//load interface media
	interface.loadMedia();

	//default direction
	dir = STOP;

	//first coordinates of head and fruit
	headX = 64;
	headY = 64;
	fruitX = rand() % 24 * 16 + 32;
	fruitY = rand() % 24 * 16 + 32;

	//default total score
	score = 0;


	high_score = 0;
	std::fstream file;
	file.open("best_score.txt");
	if (file.is_open()) {
		file >> high_score;
	
	}
	file.close();

}

//method to draw 
void game_manager::Draw() {



	//rect with size of block
	SDL_Rect block;
	block.w = BLOCK_WIDTH;
	block.h = BLOCK_HEIGHT;

	//rect with field position and size
	SDL_Rect field{ 32 , 32 ,FIELD_WIDTH ,FIELD_HEIGHT };

	//render field
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 43, 43, 43, 255);
	SDL_RenderFillRect(renderer, &field);

	//render head
	SDL_SetRenderDrawColor(renderer, 254, 84, 84, 255);
	block.x = headX;
	block.y = headY;
	SDL_RenderFillRect(renderer, &block);

	//render fruit
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	block.x = fruitX;
	block.y = fruitY;
	SDL_RenderFillRect(renderer, &block);

	for (int k = 0; k < lenth_of_tail; k++) {

		//draw tail
		SDL_SetRenderDrawColor(renderer, 231, 232, 234, 255);
		block.x = tailX[k];
		block.y = tailY[k];
		SDL_RenderFillRect(renderer, &block);

	}


	//draw score
	interface.drawScore(renderer, 3, 3, 300, 32, GetScore());
	interface.drawRecord(renderer, 564, 3, 300, 32, high_score);
	//update renderer and wait 
	SDL_RenderPresent(renderer);
	SDL_Delay(80);

}

//method to track what player input on a keyboard
void game_manager::Input()
{
	//SDL event
	SDL_Event e;

	//change direction of snake depend on key player input and remember last direction
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			game_over = true;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				if (last_dir != DOWN || lenth_of_tail == 0)
					dir = UP;
				last_dir = dir;
				break;

			case SDLK_s:
				if (last_dir != UP || lenth_of_tail == 0)
					dir = DOWN;
				last_dir = dir;
				break;
				break;

			case SDLK_d:
				if (last_dir != LEFT || lenth_of_tail == 0)
					dir = RIGHT;
				last_dir = dir;
				break;
				break;

			case SDLK_a:
				if (last_dir != RIGHT || lenth_of_tail == 0)
					dir = LEFT;
				last_dir = dir;
				break;

			}
		}
	}
}

//logic of game
void game_manager::Logic()
{
	//give coordenate of head to next block in tail(if it`s exist)
	int prewX = tailX[0];
	int prewY = tailY[0];

	int tmpX, tmpY;
	tailX[0] = headX;
	tailY[0] = headY;
	for (int i = 1; i < lenth_of_tail; ++i) {
		tmpX = tailX[i];
		tmpY = tailY[i];

		tailX[i] = prewX;
		tailY[i] = prewY;
		prewX = tmpX;
		prewY = tmpY;
	}

	//change coordinates depend on direction
	switch (dir) {
	case LEFT:
		headX -= BLOCK_WIDTH;
		break;
	case RIGHT:
		headX += BLOCK_WIDTH;
		break;
	case UP:
		headY -= BLOCK_HEIGHT;
		break;
	case DOWN:
		headY += BLOCK_HEIGHT;
		break;
	}

	//if snake head eat fruit replace fruit, add +10 to score and add +1 to tail lenth
	if (headX == fruitX && headY == fruitY) {
		fruitX = rand() % 24 * 16 + 32;
		fruitY = rand() % 24 * 16 + 32;
		score++;
		lenth_of_tail++;
		high_score = score > high_score ? score : high_score;
	}

	//if fruit was replased to tail replace fruit, add +10 to score and add +1 to tail lenth
	for (int i = 0; i < lenth_of_tail; i++) {
		if (tailX[i] == fruitX && tailY[i] == fruitY) {
			fruitX = rand() % 24 * 16 + 32;
			fruitY = rand() % 24 * 16 + 32;
			score += 1;
			lenth_of_tail++;
		}
	}

	//if snake go out from field replase it to opposite side
	if (headX > SCREEN_WIDTH - BLOCK_WIDTH - 32) {
		headX = 32;
	}
	if (headX < 32) {
		headX = SCREEN_WIDTH - BLOCK_WIDTH - 32;
	}
	if (headY > SCREEN_HEIGHT - BLOCK_HEIGHT - 32) {
		headY = 32;
	}
	if (headY < 32) {
		headY = SCREEN_HEIGHT - BLOCK_WIDTH - 32;
	}

	//if head of snake collide with the tail GAME OVER
	for (int i = 0; i < lenth_of_tail; i++) {
		if (tailX[i] == headX && tailY[i] == headY) {

			game_over = true;
			break;

		}
	}
}

//method to run game
void game_manager::Run()
{
	//setup config
	Setup();

	//while dont lose
	while (!game_over) {
		Logic();
		Input();
		Draw();
	}


	//if game is over draw "game over"
	if (GetGameStatus() == true) {
		interface.drawGameOver(renderer, 32, 32, FIELD_WIDTH, FIELD_HEIGHT);
	}

	std::fstream file;
	file.open("best_score.txt");
	if (file.is_open()) {
		
			file << high_score;
		
	}
	
	file.close();
}

//method to clear memmory
void game_manager::Free() {
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(fruitTexture);
	SDL_DestroyTexture(gameOverTextTexture);
	

	SDL_Quit();
}





