#include "Snake_game.h"


#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <SDL_image.h>

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;
const int BLOCK_WIDTH = 16;
const int BLOCK_HEIGHT = 16;

 SDL_Renderer* renderer = nullptr;
 SDL_Window* Window = nullptr;

 int headX, headY;
 int fruitX, fruitY;
 int emptyX, emptyY;
 int score;
 bool game_over = false;

 enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
 Direction dir;
 
 //std::vector<int> tailX;
 //std::vector<int> tailY;
 //int lenth_of_teil;
//moves

//first direction/move






	



void Setup()
{
	Window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	//init
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << " Error!!! \n", SDL_GetError();
	}
	game_over = false;

	dir = STOP;
	headX = 16;
	headY = 16;
	fruitX = rand() % 24 * 16;
	fruitY = rand() % 24 * 16;
	
	score = 0;
}

void Draw()
{

	/*create window and renderer*/
	

	SDL_Rect rect;
	rect.w = BLOCK_WIDTH;
	rect.h = BLOCK_HEIGHT;

	/////////
	for (int i = 0; i < SCREEN_HEIGHT; i += BLOCK_HEIGHT) {

		for (int j = 0; j < SCREEN_WIDTH; j += BLOCK_WIDTH) {
			
			

			if (i == headY && j == headX) {
				

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				rect.x = headX;
				rect.y = headY;
				SDL_RenderFillRect(renderer, &rect);

			}
			else if (i == fruitY && j == fruitX) {
				

				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
				rect.x = fruitX;
				rect.y = fruitY;
				SDL_RenderFillRect(renderer, &rect);

			}
			else {
				
				emptyY = i;
				emptyX = j;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				rect.x = emptyX;
				rect.y = emptyY;
				SDL_RenderFillRect(renderer, &rect);

			}
			SDL_RenderPresent(renderer);

			
			////////////
			
			

		}
	}


}

void Input()
{
	SDL_Event e;
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
				dir = UP;
				break;

			case SDLK_s:
				dir = DOWN;
				break;

			case SDLK_d:
				dir = RIGHT;
				break;

			case SDLK_a:
				dir =LEFT;
				break;
			}
		}
	}
}

void Logic()
{
	/*int prewX = tailX[0];
	int prewY = tailY[0];
	int tmpX, tmpY;

	for (int i = 1; i < lenth_of_teil; ++i) {
		tmpX = tailX[i];
		tmpY = tailY[i];
		tailX[i] = prewX;
		tailY[i] = prewY;
		prewX = tmpX;
		prewY=tmpY;
	}*/

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

	if (headX == fruitX && headY == fruitY) {
		fruitX = rand() % 24 * 16;
		fruitY = rand() % 24 * 16;
		score += 10;
		/*lenth_of_teil++;*/
	}

	if (headX > SCREEN_WIDTH || headX<0 || headY>SCREEN_HEIGHT || headY < 0) {
		game_over = true;
	}
}

//void game_manager::Run()
//{
//	Setup();
//	while (!game_over) {
//		Draw();
//		Input();
//		Logic();
//	}
//}



int main(int argc, char* args[]) {

	srand(time(NULL));
	Setup();
	while (!game_over) {
		Draw();
		Input();
		Logic();
	}

	return 0;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(Window);
}



