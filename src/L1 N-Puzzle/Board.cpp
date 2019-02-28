#include "Board.h"


Board::Board(const int size)
	: blank(size - 1, size - 1)
{
	this->size = size;
	this->Initialize();
}

void Board::Initialize()
{
	// Allocate space
	board = new int *[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new int[size];
	}

	// Initialize values 1-8
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (i == this->size - 1 && j == this->size - 1)
				board[i][j] = 0;
			else
			{
				board[i][j] = ((i*this->size) + j) + 1;
			}
		}
	}
}


Board::~Board()
{
	if (board)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] board[i];
		}
		delete[] board;
		board = NULL;
	}


}
void Board::Draw(void)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 0) // Draw the blanc
				std::cout << ((j == size - 1) ? "_" : "_, ");
			else // Draw the numbers
				std::cout << board[i][j] << ((j == size - 1) ? "" : ", ");
		}
		std::cout << std::endl;
	}
}
void Board::SwitchUp(void)
{
	if (this->blank.GetY() > 0)
	{
		Switch(0, -1);
		blank.DecreaseY();
	}
}
void Board::SwitchDown(void)
{
	if (this->blank.GetY() < this->size - 1)
	{
		Switch(0, 1);
		blank.IncreaseY();
	}
}
void Board::SwitchLeft(void)
{
	if (this->blank.GetX() > 0)
	{
		Switch(-1, 0);
		blank.DecreaseX();
	}
}
void Board::SwitchRight(void)
{
	if (this->blank.GetX() < this->size - 1)
	{
		Switch(1, 0);
		blank.IncreaseX();
	}
}

void Board::Switch(int x, int y)
{
	board[this->blank.GetY()][this->blank.GetX()] = board[this->blank.GetY() + y][this->blank.GetX() + x];
	board[this->blank.GetY() + y][this->blank.GetX() + x] = 0;
}

void Board::Shuffle(void)
{
	int shuffleCount = rand() % 450 + 50;
	int counter = 0;

	for (int i = shuffleCount - 1; i >= 0; i--)
	{
		int temp = rand() % 4;
		switch (temp)
		{
		case 0:
			this->SwitchUp();
			break;
		case 1:
			this->SwitchDown();
			break;
		case 2:
			this->SwitchLeft();
			break;
		case 3:
			this->SwitchRight();
			break;
		}
	}
}
bool Board::IsCompleted(void)
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			int compare = ((i*this->size) + j) + 1;
			if (i == this->size - 1 && j == this->size - 1) // Last space should be blank
				compare = 0; // Blank space is 0

			if (board[i][j] != compare)
			{
				return false;
			}
		}
	}
	return true;
}
