#pragma once
#include <iostream>
#include <conio.h>
#include "Board.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game
{
public:
	Game(int PuzzleSize);
	~Game();
	void Run(void);
	void PrintInstructions(void);
private:
	Board board;
	void ProcessInput(void);
	void ClearScreen(void);

};

