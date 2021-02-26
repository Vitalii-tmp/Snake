#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <SDL_image.h>
#include "Interfase.h"
#include<fstream>

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

//class
class game_manager
{
	const int SCREEN_WIDTH = 864;
	const int SCREEN_HEIGHT = 464;
	const int FIELD_WIDTH = 800;
	const int FIELD_HEIGHT = 400;
	const int BLOCK_WIDTH = 16;
	const int BLOCK_HEIGHT = 16;

	//windiw and renderer
	SDL_Renderer* renderer = nullptr;
	SDL_Window* Window = nullptr;

	//textures
	SDL_Texture* fruitTexture;
	SDL_Texture* gameOverTextTexture;
	
	Interfase interface;
	
	//coordinates of head and fruit
	int headX, headY;
	int fruitX, fruitY;

	//score (how match snake eat)
	int score, high_score;
	bool game_over = false;

	//enumeration of directions
	enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
	Direction dir;
	Direction last_dir;

	//arrays whitch save coordinates tail
	int tailX[1250];
	int tailY[1250];

	//lenth of tail
	int lenth_of_tail = 0;

	//methods
	void Setup();
	void Draw();
	void Input();
	void Logic();
	
public:
	//methods
	void Run();
	void Free();
	
	bool GetGameStatus() {
		return game_over;
	}

	int GetScore() {
		return this->score;
	}


};


