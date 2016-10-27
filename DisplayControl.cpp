// 
// 
// 

#include "DisplayControl.h"

DisplayControlClass::DisplayControlClass() {
	//lc = LedControl(12, 11, 10, 1);

	lc.shutdown(0, false);
	/* Set the brightness to a medium values */
	lc.setIntensity(0, 8);
	/* and clear the display */
	lc.clearDisplay(0);
}
void DisplayControlClass::FillCell(int x, int y, DisplayCellType cellType)
{
	display[x][y] = cellType;
}

DisplayCellType DisplayControlClass::GetCell(int x, int y)
{
	return display[x][y];
}

void DisplayControlClass::init()
{
	for (int i = 0; i < DISPLAY_LENGTH_X; i++)
		for (int j = 0; j < DISPLAY_LENGTH_Y; j++)
			display[i][j] = None;
}

void DisplayControlClass::highlight(int step)
{
	for (int i = 0; i < DISPLAY_LENGTH_X; i++) {
		displayRow[i] = 0;
		for (int j = 0; j < DISPLAY_LENGTH_Y; j++) {
			if (display[i][j] != None &&
				!(display[i][j] == SnakeFood && step % 2 == 0) &&
				!(display[i][j] == SnakeHead && step % 5 == 0)
				)
				displayRow[i] |= 1 << j;
				//				None
				//
				//				SnakeBody,
				//				SnakeTail,
				//				SnakeHead,
				//
				//				SnakeFood)
		}
		lc.setRow(0, i, displayRow[i]);
//		lc.setRow(0, i, B10001000);
	}
	for (int i = 0; i < 8; ++i)
	{

	}
}

//DisplayControlClass DisplayControl;

