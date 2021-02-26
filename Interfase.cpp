#include "Interfase.h"
#include <fstream>


void Interfase::loadMedia()
{
	 fruit = IMG_Load("apple.png");
	font = TTF_OpenFont("pixel_font.ttf", 70);
	 gameOverText = IMG_Load("gameOver.png");
	

}


void Interfase::drawScore(SDL_Renderer* renderer, int x, int y, int WIDTH, int HEIGHT,int score)
{
	
	SDL_Rect dest = { x,y, WIDTH,HEIGHT };
	SDL_Color color = { 43,43,43 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, ("TOTAL SCORE: "+ std::to_string(score)).c_str(), color);
	//Create texture from surface pixels

	SDL_Texture* Text = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, Text, NULL, &dest);
	SDL_FreeSurface(textSurface);
}

void Interfase::drawGameOver(SDL_Renderer* renderer ,int x,int y, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	gameOverTextTexture = SDL_CreateTextureFromSurface(renderer, gameOverText);
	SDL_Rect rect = { x,y,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(renderer, gameOverTextTexture, NULL, &rect);
	SDL_RenderPresent(renderer);
}

void Interfase::drawRecord(SDL_Renderer* renderer, int x, int y, int WIDTH, int HEIGHT,int record)
{
	

	SDL_Rect dest = { x,y, WIDTH,HEIGHT };
	SDL_Color color = { 43,43,43 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, ("HIGHEST SCORE: "+std::to_string(record)).c_str(), color);
	//Create texture from surface pixels

	SDL_Texture* Text = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, Text, NULL, &dest);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(Text);
}

void Interfase::free()
{
	SDL_FreeSurface(fruit);
	SDL_FreeSurface(gameOverText);
}


void renderRecord()
{
}
