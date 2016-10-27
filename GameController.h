// GameController.h

#ifndef _GAMECONTROLLER_h
#define _GAMECONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "SnakeState.h"

const int steps = 10;
class GameControllerClass
{
 protected:
	 SnakeStateClass snake;
	 DisplayControlClass display;
	 int snakeLength;

	 int joystickPortX;
	 int joystickPortY;

	static DisplayCellType ConvertToDisplayCell(FieldCellType fieldType);
	 void UpdateDisplay();
public:
	GameControllerClass();
	void init(int portX, int portY);
	static boolean HasDirection(int value);
	void ReadJoystick();
	void Loop();
};

extern GameControllerClass GameController;

#endif

