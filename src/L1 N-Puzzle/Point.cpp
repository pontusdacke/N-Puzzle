#include "Point.h"

Point::Point(int x, int y)
	: x(x), y(y)
{
}
Point::~Point()
{
}
int Point::GetX(void)
{
	return this->x;
}
int Point::GetY(void)
{
	return this->y;
}
void Point::IncreaseX(void)
{
	this->x++;
}
void Point::IncreaseY(void)
{
	this->y++;
}
void Point::DecreaseX(void)
{
	this->x--;
}
void Point::DecreaseY(void)
{
	this->y--;
}