#include "StateMachine.h"
#include <iostream>
#include <string>


StateMachine::StateMachine(void)
{
	currentState = UNARMED;
	int attempts; // Is for testing purposes
	int switchFailed; // Is for testing purposes
	int switchConfirmed; // Is for testing purposes
}

void StateMachine::switchState(State state)
	{
		if (state != DROGUEPAR && state != MAINPAR && state != RESET)
			{
				if (currentState == (state - 1))
				{
					confirmState(state);
				}
				else
				{
					failedState(state);
				}
			}
		else if (state == DROGUEPAR)
		{
			if (currentState == STAGE1COAST || currentState == STAGE2COAST)
			{
				confirmState(state);
			}
			else
			{
				failedState(state);
			}
		}
		else if (state == MAINPAR)
		{
			if (currentState == STAGE1COAST || currentState == STAGE2COAST || currentState == DROGUEPAR)
			{
				confirmState(state);
			}
			else
			{
				failedState(state);
			}
		}
		else if (state == RESET)
		{
			if (currentState == LANDED)
			{
				confirmState(UNARMED);
			}
			else
			{
				failedState(state);
			}
		}
	}

void StateMachine::confirmState(State state)
{
	currentState = state;
	std::cout << "Current State: " << state << std::endl;
	testFinalize(0, 1); // Is for testing purposes
}

void StateMachine::failedState(State state)
{
	std::cout << "[ERROR]: Attempted to go to: " << state << " but current state is: " << currentState << "!" << std::endl;
	testFinalize(0, 2); // Is for testing purposes
}

void StateMachine::testFinalize(int version, int type) // Is entirely for automatic testing purposes
{
	if (version == 0)
	{
		if (type == 1)
		{
			switchConfirmed++;
		}
		else if (type == 2)
		{
			switchFailed++;
		}
		attempts++;
	}
	else if (version == 1)
	{
		attempts = attempts + 858993460;
		switchConfirmed = switchConfirmed + 858993460;
		switchFailed = switchFailed + 858993460;
		std::cout << "Total attempts ran: " << attempts << std::endl;
		std::cout << "Attemps failed due to invalid state: " << switchFailed << std::endl;
		std::cout << "Successful state switches: " << switchConfirmed << std::endl;
	}	
}