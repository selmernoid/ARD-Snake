// SnakeState.h

#ifndef _SNAKESTATE_h
#define _SNAKESTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "DisplayControl.h"

enum FieldCellType
{
	Empty = 0,

	Up,
	Down,
	Left,
	Right,

	Food
};

struct Point
{
public: int X, Y;
public: Point(int x, int y);
public: Point();
};


class SnakeStateClass
{
protected:
	FieldCellType field[DISPLAY_LENGTH_X][DISPLAY_LENGTH_Y];
	Point Start, End;
	int length;
	boolean withBorders;
	FieldCellType backwardWay;

	Point EvaluateNextPoint(Point point);
	Point GetNextPoint(Point point);
	static FieldCellType GetBackwardWay(FieldCellType way);
public:
	SnakeStateClass();
	SnakeStateClass(boolean withBorders);
	void Lose();
	void CreateFood();
	void DoStep();
	void ChangeDirection(FieldCellType way);
	void init(int startSize);
	int GetLength() const;

	FieldCellType GetCell(int x, int y);
	Point GetHead() const;
	Point GetTail() const;
};

extern SnakeStateClass SnakeState;

#endif

