#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include "Snake_game.h"


SDL_Window* Window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char* args[]) {
	
	
	game_manager game;

	game.perform_game_session(Window, renderer);

	SDL_Delay(2000);





	return 0;
}