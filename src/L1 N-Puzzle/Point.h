#pragma once
class Point
{
public:
	Point(int x, int y);
	~Point();
	void IncreaseX(void);
	void IncreaseY(void);
	void DecreaseX(void);
	void DecreaseY(void);
	int GetX(void);
	int GetY(void);
private:
	int x;
	int y;
};

