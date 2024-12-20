#pragma once

#include "ICommand.h"

class InputHandler
{
public:

	ICommand* HandlerInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();

private:
	
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
};

