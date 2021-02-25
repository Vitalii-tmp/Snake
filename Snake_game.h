#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <SDL_image.h>


//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 800;
//const int BLOCK_WIDTH = 16;
//const int BLOCK_HEIGHT = 16;
//
//static SDL_Renderer* renderer=nullptr;
//static SDL_Window* Window = nullptr;
//
//static int headX, headY;
//static int fruitX, fruitY;
//static int emptyX, emptyY;
//static int score;
//static bool game_over = false;
//
//static enum Direction {STOP = 0,LEFT,RIGHT,UP,DOWN};
//static Direction dir;

//moves

//first direction/move





class game_manager
{
	void Setup();
	void Draw();
	void Input();
	void Logic();
	
public:
	
	void Run();

	void Free();
	

	
};


