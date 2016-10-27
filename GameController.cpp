// 
// 
// 

#include "GameController.h"

DisplayCellType GameControllerClass::ConvertToDisplayCell(FieldCellType fieldType)
{
	switch (fieldType){
	case Down:
	case Left:
	case Right:
	case Up:
		return SnakeBody;
	case Food:
		return SnakeFood;
	case Empty:
	default:
		return None;		
	}
}

void GameControllerClass::UpdateDisplay()
{
	Point head = snake.GetHead();
	Point tail = snake.GetTail();
	for (int i = 0; i < DISPLAY_LENGTH_X; i++)
		for (int j = 0; j < DISPLAY_LENGTH_Y; j++)
		{
			if (head.X == i && head.Y == j) {
				display.FillCell(i, j, SnakeHead);
				continue;
			}
			if (tail.X == i && tail.Y == j) {
				display.FillCell(i, j, SnakeTail);
				continue;
			}			
			display.FillCell(i, j, ConvertToDisplayCell(snake.GetCell(i, j)));
		}
}

GameControllerClass::GameControllerClass()
{
	snakeLength = 0;
//	this->snake = SnakeStateClass(false);
	this->snake = *new SnakeStateClass(false);
	this->display = *new DisplayControlClass();

}

void GameControllerClass::init(int portX, int portY)
{
	this->snake.init(3);
	this->display.init();
	joystickPortX = portX;
	joystickPortY = portY;

	snake.DoStep();
}

boolean GameControllerClass::HasDirection(int value)
{
	return abs(value) > 300;
}
void GameControllerClass::ReadJoystick()
{
	int mediana = 512;
	int x = analogRead(joystickPortX) - mediana;
	int y = analogRead(joystickPortY) - mediana;

	if (abs(x) > abs(y))
	{
		if (HasDirection(x))
			snake.ChangeDirection(x > 0 ? Right : Left);
	} else 
		if (HasDirection(y))
			snake.ChangeDirection(y > 0 ? Up : Down);
}
void GameControllerClass::Loop()
{
	snakeLength = snake.GetLength();

	if (snake.IsLose())
	{
		int steps = snake.GetSteps();
		display.ShowStats(steps, snakeLength);
		snake.init(3);
	}
	else {
		UpdateDisplay();

		int totalDelay = 600 - 10 * snakeLength;
		int stepDelay = totalDelay / steps;
		for (int i = 0; i < steps; i++) {
			ReadJoystick();
			display.highlight(i);
			delay(stepDelay);
		}
	}

	snake.DoStep();
}


GameControllerClass GameController;

