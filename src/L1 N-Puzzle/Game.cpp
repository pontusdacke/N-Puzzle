#include "Game.h"


Game::Game(int puzzleSize)
	: board(puzzleSize)
{
}

Game::~Game()
{
}

void Game::Run(void)
{
	while (1) // Infinite game loop
	{
		this->board.Shuffle();
		while (!this->board.IsCompleted())
		{
			this->ClearScreen();
			this->board.Draw();
			this->PrintInstructions();

			this->ProcessInput();
		}

		this->ClearScreen();
		cout << "YOU WIN. Press any key to restart";
		_getch();
	}
	
}

void Game::ProcessInput(void)
{
	switch (_getch()) { // the real value
	case KEY_UP:
		this->board.SwitchUp();
		break;
	case KEY_DOWN:
		this->board.SwitchDown();
		break;
	case KEY_RIGHT:
		this->board.SwitchRight();
		break;
	case KEY_LEFT:
		this->board.SwitchLeft();
		break;
	}
}

void Game::ClearScreen(void)
{
	system("CLS");
}

void Game::PrintInstructions(void)
{
	cout << endl << endl << "Control the blank piece with arrow keys" << endl;
}