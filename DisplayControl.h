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
	void ShowStats(int steps, int length);
};


const static uint8_t alphabet[10][6] = {
	{ 0x7E,0x81,0x81,0x81,0x7E,0x0 }, //0
	{ 0x4,0x82,0xFF,0x80,0x0,0x0 },  //1
	{ 0xE2,0x91,0x91,0x91,0x8E,0x0 },//2
	{ 0x42,0x89,0x89,0x89,0x76,0x0 },//3
	{ 0x1F,0x10,0x10,0xFF,0x10,0x0 },//4
	{ 0x8F,0x89,0x89,0x89,0x71,0x0 },//5
	{ 0x7E,0x89,0x89,0x89,0x71,0x0 },//6
	{ 0x1,0x1,0xF9,0x5,0x3,0x0 },//7
	{ 0x76,0x89,0x89,0x89,0x76,0x0 },//8
	{ 0x8E,0x91,0x91,0x91,0x7E,0x0 },//9	
};


extern DisplayControlClass DisplayControl;

#endif

