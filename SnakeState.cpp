// 
// 
// 

#include "SnakeState.h"

Point::Point(int x, int y){ this->X = x;  this->Y = y; }
Point::Point() { X = 0; Y = 0; }

Point SnakeStateClass::EvaluateNextPoint(Point point)
{
	FieldCellType way = field[point.X][point.Y];
	switch (way)
	{
	case Down: return Point(point.X, point.Y - 1);
	case Left: return Point(point.X - 1, point.Y);
	case Right: return Point(point.X + 1, point.Y);
	case Up: return Point(point.X, point.Y + 1);
	}
	return Point(-1, -1);
}

Point SnakeStateClass::GetNextPoint(Point point)
{
	Point result = EvaluateNextPoint(point);

	if (!withBorders)
	{
		result.X = (result.X + DISPLAY_LENGTH_X) % DISPLAY_LENGTH_X;
		result.Y = (result.Y + DISPLAY_LENGTH_Y) % DISPLAY_LENGTH_Y;
	}
	return result;

}
FieldCellType SnakeStateClass::GetBackwardWay(FieldCellType way)
{
	switch (way)
	{
	case Up: return Down;
	case Down: return Up;

	case Left: return Right;
	case Right: return Left;
	}
	return Empty;
}

SnakeStateClass::SnakeStateClass()
{
	this->withBorders = false;
}

SnakeStateClass::SnakeStateClass(boolean withBorders)
{
	this->withBorders = withBorders;
}

void SnakeStateClass::Lose()
{
	init(3);
}

void SnakeStateClass::CreateFood()
{
	while (true)
	{
		int random = rand() % (DISPLAY_LENGTH_X * DISPLAY_LENGTH_Y);
		FieldCellType* point = &field[random / DISPLAY_LENGTH_X][random % DISPLAY_LENGTH_X];
		if (*point == Empty)
		{
			*point = Food;
			break;
		}

	}
}

void SnakeStateClass::DoStep()
{
	Point nextCell = GetNextPoint(End);

	if (nextCell.X < 0 || nextCell.X >= DISPLAY_LENGTH_X ||
		nextCell.Y < 0 || nextCell.Y >= DISPLAY_LENGTH_Y) {
		Lose();
		return;
	}

	FieldCellType nextCellWay = field[nextCell.X][nextCell.Y];

	if (nextCellWay != Food && nextCellWay != Empty) {
		Lose();
		return;
	}

	if (nextCellWay != Food)
	{
		Point newStart = GetNextPoint(Start);
		field[Start.X][Start.Y] = Empty;
		Start = newStart;
	}
	else
		CreateFood();
	
	field[nextCell.X][nextCell.Y] = field[End.X][End.Y];
	backwardWay = GetBackwardWay(field[End.X][End.Y]);
	End = nextCell;
}

void SnakeStateClass::ChangeDirection(FieldCellType way)
{
	if (way != backwardWay)
		field[End.X][End.Y] = way;
}

void SnakeStateClass::init(int startSize)
{
	for (int i = 0; i < DISPLAY_LENGTH_X; i++)
		for (int j = 0; j < DISPLAY_LENGTH_Y; j++)
			field[i][j] = Empty;

	for (int i = 0; i < startSize; i++)
		field[i][0] = Right;
	Start = Point(0, 0);
	End = Point(startSize - 1, 0);
	length = startSize;

	backwardWay = Left;

	CreateFood();
}

int SnakeStateClass::GetLength() const
{
	return length;
}

//SnakeStateClass SnakeState;

FieldCellType SnakeStateClass::GetCell(int x, int y)
{
	return field[x][y];
}

Point SnakeStateClass::GetHead() const { return End; }
Point SnakeStateClass::GetTail() const { return Start; }
