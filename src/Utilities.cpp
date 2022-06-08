#include "Utilities.h"


//function that get the position from the index of the board
Vector2f setTilePosition(const LocIndx loc)
{
	auto row = loc.first;
	auto col = loc.second;
	Vector2f pos = startPos;
	if (row % 2 == 1) pos.x += 30.f;

	return Vector2f(pos.x + col * BoardSpace.x, pos.y + row * BoardSpace.y);
}

//function that returns -1 if num is even and 1 if is odd
int oddOrEven(const int num)
{
	return (num % 2 * 2) - 1;
}

float distance(const Vector2f& p1, const Vector2f& p2)
{
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.x - p2.x), 2));
}