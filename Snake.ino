#include "LedControlMS.h"
#include "GameController.h"
#include "DisplayControl.h"
#include "SnakeState.h"

GameControllerClass* game;
void setup()
{
	game = new GameControllerClass();
	Serial.begin(115200);
	game->init(0, 1);
  /* add setup code here */

}

void loop()
{
	game->Loop();
  /* add main program code here */

}
