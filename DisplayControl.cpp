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

void DisplayControlClass::ShowStats(int steps, int length)
{
	delay(1000);
	for (int i = 0; i < 64; i++)
	{
		lc.setLed(0, i / 8, i % 8, true);
		delay(25);	
	}
	delay(200);
	lc.clearDisplay(0);

	int digits = length > 9 ? 2 : 1;
	int *array = new int[digits];	
	if (digits == 1)
		array[0] = length;
	else {
		array[0] = length / 10;
		array[1] = length % 10;
	}

	int rowsCount =
		(digits) * 6
		+ (digits - 1) /*пробелы между символами*/
		+ 2 * 8 /*пустота в начале и в конце*/
		;// +8 /*чтоб пробежало по всем клеткам*/;

	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (j + i < 8 || j + i >= rowsCount - 8)
				lc.setRow(0, j, 0);
			else {
				int symbolIdx = (j + i - 8) / (6 + 1);
				int symbolRow = (j + i - 8) % (6 + 1);
				if (symbolRow == 6 || symbolIdx > digits)
					lc.setRow(0, j, 0);
				else
				{
					lc.setRow(0, j, alphabet[array[symbolIdx]][symbolRow]);
				}					
			}
		}

		delay(230);
	}

	delete[]array;

//	for (int i = 0; i<6; i++) {
//		lc.setRow(0, i, alphabetBitmap[charIndex][i]);
//	}
//	alphabetBitmap[0];
}

//DisplayControlClass DisplayControl;

