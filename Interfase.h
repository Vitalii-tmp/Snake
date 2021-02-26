#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include<SDL_ttf.h>
class Interfase
{
	SDL_Surface* fruit;
	SDL_Surface* gameOverText;
	SDL_Texture* gameOverTextTexture;
	TTF_Font* font;


public:
	void loadMedia();
	void drawScore(SDL_Renderer* renderer, int x, int y, int WIDTH, int HEIGHT, int score);
	void drawGameOver(SDL_Renderer* renderer, int x, int y, int SCREEN_WIDTH, int SCREEN_HEIGHT);
	void drawRecord(SDL_Renderer* renderer, int x, int y, int WIDTH, int HEIGHT, int score);
	
};

