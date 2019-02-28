#pragma once

#include <iostream>
#include "Point.h"

class Board
{
public:
	Board(int size);
	~Board();
	void SwitchUp(void);
	void SwitchDown(void);
	void SwitchLeft(void);
	void SwitchRight(void);
	void Shuffle(void);
	void Draw(void);
	bool IsCompleted(void);
private:
	void Switch(int x, int y);
	void Initialize();
	int **board;
	Point blank;
	int size;
};

