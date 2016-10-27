// DisplayControl.h

#ifndef _DISPLAYCONTROL_h
#define _DISPLAYCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LedControlMS.h"
#define DISPLAY_LENGTH_X 8
#define DISPLAY_LENGTH_Y 8
enum DisplayCellType
{
	None = 0,

	SnakeBody,
	SnakeTail,
	SnakeHead,

	SnakeFood
};
class DisplayControlClass
{
 protected:
	 DisplayCellType display[DISPLAY_LENGTH_X][DISPLAY_LENGTH_Y];
	 uint8_t displayRow[DISPLAY_LENGTH_X];
	 LedControl lc = LedControl(12, 11, 10, 1);
 public:
	DisplayControlClass();
	void FillCell(int x, int y, DisplayCellType cellType);
	 DisplayCellType GetCell(int x, int y);
	void init();
	void highlight(int delay);
};

extern DisplayControlClass DisplayControl;

#endif

