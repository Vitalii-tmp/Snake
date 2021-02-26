#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include<ctime>
#include "Snake_game.h"
#include "Interfase.h"


int main(int argc, char* args[]) {
	//randow
	srand(NULL);
	
	//object of game manager class
	game_manager game;
	
	//run game
	game.Run();

	//after game wait 5 sec
	SDL_Delay(5000);

	//clean memmory
	game.Free();
	
	return 0;
}