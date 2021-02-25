#include "Snake_game.h"


#pragma once


#include <string>
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

const int SCREEN_WIDTH = 464;
const int SCREEN_HEIGHT = 464;
const int FIELD_WIDTH = 400;
const int FIELD_HEIGHT = 400;
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
Direction last_dir;


int tailX[625];
int tailY[625];
int lenth_of_teil=0;








 

void game_manager::Setup()
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
	headX = 64;
	headY = 64;
	fruitX = rand() % 24 * 16 +32;
	fruitY = rand() % 24 * 16 +32;

	score = 0;
}

//void Draw()
//{
//
//	/*create window and renderer*/
//	
//
//	SDL_Rect rect;
//	rect.w = BLOCK_WIDTH;
//	rect.h = BLOCK_HEIGHT;
//
//	/////////
//	for (int i = 0; i < SCREEN_HEIGHT; i += BLOCK_HEIGHT) {
//
//		for (int j = 0; j < SCREEN_WIDTH; j += BLOCK_WIDTH) {
//			
//			
//
//			if (i == headY && j == headX) {
//				
//
//				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//				rect.x = headX;
//				rect.y = headY;
//				SDL_RenderFillRect(renderer, &rect);
//
//			}
//			else if (i == fruitY && j == fruitX) {
//				
//
//				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//				rect.x = fruitX;
//				rect.y = fruitY;
//				SDL_RenderFillRect(renderer, &rect);
//
//			}
//			else {
//				
//
//				//for (int k = 0; k < lenth_of_teil; k++) {
//				//	if (tailX[k] == j && tailY[k] == i) {
//				//		//draw tail
//				//		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//				//		rect.x = tailX[k];
//				//		rect.y = tailY[k];
//				//		SDL_RenderFillRect(renderer, &rect);
//
//				//		
//				//	}
//				//}
//
//				/*if (tailX[j] != j && tailY[i] != i && i != fruitY && j != fruitX && i != headY && j != headX) {
//					emptyY = i;
//					emptyX = j;
//				}*/
//				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 2555);
//				rect.x = emptyX;
//				rect.y = emptyY;
//				SDL_RenderFillRect(renderer, &rect);
//
//
//			}
//			SDL_RenderPresent(renderer);
//
//			
//			////////////
//			
//			
//
//		}
//	}
//
//
//}
void game_manager::Draw() {

	/*create window and renderer*/


	SDL_Rect rect;
	rect.w = BLOCK_WIDTH;
	rect.h = BLOCK_HEIGHT;
	SDL_Rect field{32 , 32 ,FIELD_WIDTH ,FIELD_HEIGHT };
	
	//render field
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &field);
	
	//render head
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	rect.x = headX;
	rect.y = headY;
	SDL_RenderFillRect(renderer, &rect);

//render fruit
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	rect.x = fruitX;
	rect.y = fruitY;
	SDL_RenderFillRect(renderer, &rect);
	
	for (int k = 0; k < lenth_of_teil; k++) {

		//draw tail
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		rect.x = tailX[k];
		rect.y = tailY[k];
		SDL_RenderFillRect(renderer, &rect);


	}

	SDL_RenderPresent(renderer);
	SDL_Delay(100);

}


void game_manager::Input()
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
				if (last_dir != DOWN || lenth_of_teil == 0)
				dir = UP;
				last_dir = dir;
				break;

			case SDLK_s:
				if (last_dir != UP || lenth_of_teil == 0)
					dir = DOWN;
				last_dir = dir;
				break;
				break;

			case SDLK_d:
				if (last_dir != LEFT || lenth_of_teil == 0)
					dir = RIGHT;
				last_dir = dir;
				break;
				break;

			case SDLK_a:
				if (last_dir != RIGHT || lenth_of_teil == 0)
				last_dir = dir;
				break;
				break;
			}
		}
	}
}

void game_manager::Logic()
{
	int prewX = tailX[0];
	int prewY = tailY[0];

	int tmpX, tmpY;
	tailX[0] = headX;
	tailY[0] = headY;
	for (int i = 1; i < lenth_of_teil; ++i) {
		tmpX = tailX[i];
		tmpY = tailY[i];

		tailX[i] = prewX;
		tailY[i] = prewY;
		prewX = tmpX;
		prewY=tmpY;
	}

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
		fruitX = rand() % 24 * 16  + 32;
		fruitY = rand() % 24 * 16  + 32;
		score += 10;
		lenth_of_teil++;
	}

	if (headX > SCREEN_WIDTH-BLOCK_WIDTH-32) {
		headX = 32;
	}
	if (headX < 32) {
		headX = SCREEN_WIDTH - BLOCK_WIDTH-32;
	}
	if (headY > SCREEN_HEIGHT-BLOCK_HEIGHT-32) {
		headY = 32;
	}
	if (headY < 32) {
		headY = SCREEN_HEIGHT - BLOCK_WIDTH-32;
	}


	for (int i = 0; i < lenth_of_teil; i++) {
		if (tailX[i] == headX && tailY[i] == headY) {
			game_over=true;
		}
	}
}

void game_manager::Run()
{
	Setup();
	while (!game_over) {
		Draw();
		Input();
		Logic();
	}
}

void game_manager::Free() {
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
}

//int main(int argc, char* args[]) {
//	
//	srand(time(NULL));
//	Setup();
//	while (!game_over) {
//		Draw();
//		Input();
//		Logic();
//	}
//
//	return 0;
//
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(Window);
//}



